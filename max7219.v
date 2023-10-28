
// modified by L.-C. Duca 20231028
// a stable way to print on max7219 display
// original source - https://github.com/cerkit/max7219TinyFPGA

module max7219(clk, clkdiv, reset_n, data_vector, clk_out, data_out, load_out);

input wire clk, clkdiv, reset_n;
input wire [31:0] data_vector;
output reg clk_out, data_out, load_out;

localparam ActiveDigits = 8;
localparam DataBits = ActiveDigits * 4;
localparam CommandRegSize = 16;

//reg [3:0] digits [0:7];
// state
`define reset 0
`define init_on 1
`define init_mode 2
`define init_intensity 3
`define init_scan 4
`define latch_data 5
`define send_digits 6
`define finish_state 7
`define wait_state 8
reg [7:0] state=`reset, next_state;

// driver_state
`define ds_idle 0
`define ds_start 1
`define ds_clk_data 2
`define ds_clk_high 3
`define ds_clk_low 4
`define ds_finished 5
`define ds_pre_clk_high 6
`define ds_pre_clk_low 7
`define ds_pre_clk_low2 8
reg [7:0] driver_state=`ds_idle;
reg start_ds=0;
reg [15:0] command_reg=0;
reg [15:0] counter=0;
reg [3:0] digit_index=7;
reg [7:0] segments;
reg [7:0] ds_cnt=0;

always @(posedge clk) 
begin
	if (reset_n == 0) begin
            driver_state <= `ds_idle;
            state        <= `reset;
            load_out     <= 0;
            counter      <= 0;
            digit_index  <= 7;
	    command_reg <= 16'h0c00;
	    start_ds <= 0;
		ds_cnt <= 0;
	end else begin
		if(clkdiv) begin
	    case(state)
		    `reset:
			    if(driver_state == `ds_idle) begin
					command_reg <= 16'h0c00;
					// Shutdown Register (0x0C): Shutdown Mode (0x00)
					start_ds <= 1;
					next_state        <= `init_on;
					state <= `wait_state;
				end
			`init_on:
				if (driver_state == `ds_idle) begin
					// Shutdown Register (0x0C): Normal Operation (0x01)
					command_reg <= 16'h0c01;
					start_ds <= 1;
					next_state        <= `init_mode;
					state <= `wait_state;
			    end
			`init_mode:
			    if (driver_state == `ds_idle) begin
					// Decode-Mode Register (0x09): No decode for digits 7-0 (0x00)
					command_reg <= 16'h0900;
					start_ds <= 1;
					next_state        <= `init_intensity;
					state <= `wait_state;
			    end
			`init_intensity:
				if (driver_state == `ds_idle) begin
					// Intensity Register (0x0A)
					command_reg <= {12'h0a0, 4'h3};
					start_ds <= 1;
					next_state        <= `init_scan;
					state <= `wait_state;
				end
			`init_scan:
			    if (driver_state == `ds_idle) begin
					// Scan-Limit Register(0x0B): Display digits 0 1 2 3 4 5 6 7 (0x07)
					command_reg <= 16'h0b07;
					start_ds <= 1;
					next_state        <= `latch_data;
					state <= `wait_state;
			    end
		    `latch_data: begin
					`ifdef laur0
					digits[7] <= data_vector[31:28];
					digits[6] <= data_vector[27:24];
					digits[5] <= data_vector[23:20];
					digits[4] <= data_vector[19:16];
					digits[3] <= data_vector[15:12];
					digits[2] <= data_vector[11:8];
					digits[1] <= data_vector[7:4];
					digits[0] <= data_vector[3:0];
					`endif
					digit_index <= 7;
					state <= `send_digits;
		    end
			`send_digits: 
				if (driver_state == `ds_idle) begin
					command_reg <= {4'h0, digit_index + 1, segments};
					start_ds <= 1;
					if (digit_index == 0) begin
						//next_state <= `latch_data;
						next_state <= `finish_state;
						state <= `wait_state;
					end else begin
						digit_index <= digit_index - 4'h1;
						next_state <= `send_digits;
						state <= `wait_state;
					end
				end
		    `wait_state: begin
				if(driver_state != `ds_idle) begin
					state <= next_state;
					start_ds <= 0;
				end
			end
		    `finish_state: begin
				if(driver_state == `ds_idle)
					state <= `latch_data;
					//state <= `reset;
			end
            endcase

            case (driver_state)
		    `ds_idle: begin
				load_out <= 1;
				clk_out  <= 0;
				ds_cnt <= ds_cnt + 1;
				if(start_ds && ds_cnt > 10) begin
					ds_cnt <= 0;
					driver_state <= `ds_start;
				end
			end
		    `ds_start: begin
				load_out <= 0;
				counter <= CommandRegSize;
				driver_state <= `ds_clk_data;
		    end
			`ds_clk_data: begin
				counter <= counter - 16'h1;
				data_out <= command_reg[counter - 1];
				driver_state <= `ds_pre_clk_high;
			end
			`ds_pre_clk_high: begin
				driver_state <= `ds_clk_high;
			end
			`ds_clk_high: begin
				clk_out      <= 1;
				driver_state <= `ds_pre_clk_low;
			end
			`ds_pre_clk_low: begin
				driver_state <= `ds_pre_clk_low2;
			end
			`ds_pre_clk_low2: begin
				driver_state <= `ds_clk_low;
			end
			`ds_clk_low: begin
				clk_out <= 0;
				if (counter == 0) begin
					load_out     <= 1;
					driver_state <= `ds_finished;
				end else
					driver_state <= `ds_clk_data;
			end 
			`ds_finished: begin
				driver_state <= `ds_idle;
				ds_cnt <= 0;
			end
            endcase
        end
		end
    end

wire [3:0] mydigits;
//assign mydigits = digits[digit_index];
assign mydigits = 
			digit_index == 7 ? data_vector[31:28] :
			digit_index == 6 ? data_vector[27:24] :
			digit_index == 5 ? data_vector[23:20] :
			digit_index == 4 ? data_vector[19:16] :
			digit_index == 3 ? data_vector[15:12] :
			digit_index == 2 ? data_vector[11:8]  :
			digit_index == 1 ? data_vector[7:4]   :
			data_vector[3:0] ;


    always @(*)
    begin
        case (mydigits)
                // +----+----+----+----+----+----+----+----+
                // | D7 | D6 | D5 | D4 | D3 | D2 | D1 | D0 |
                // +----+----+----+----+----+----+----+----+
                // | DP | A  | B  | C  | D  | E  | F  | G  |
                // +----+----+----+----+----+----+----+----+
            4'b0000: segments <= 8'b01111110; // 0
            4'b0001: segments <= 8'b00110000; // 1
            4'b0010: segments <= 8'b01101101; // 2
            4'b0011: segments <= 8'b01111001; // 3
            4'b0100: segments <= 8'b00110011; // 4
            4'b0101: segments <= 8'b01011011; // 5
            4'b0110: segments <= 8'b01011111; // 6
            4'b0111: segments <= 8'b01110000; // 7
            4'b1000: segments <= 8'b01111111; // 8
            4'b1001: segments <= 8'b01111011; // 9
            4'b1010: segments <= 8'b01111101; // a
            4'b1011: segments <= 8'b00011111; // b
            4'b1100: segments <= 8'b00001101; // c
            4'b1101: segments <= 8'b00111101; // d
            4'b1110: segments <= 8'b01001111; // E
            4'b1111: segments <= 8'b01000111; // F
            default:  segments <= 8'b10000000; // .
        endcase
    end


endmodule
