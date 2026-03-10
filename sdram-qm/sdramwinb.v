`default_nettype wire
module sdramwinb(clk,rst,
				data,addr,ba,
				cke,
				cs_n,ras_n,cas_n,we_n,dqm, dqmi, uaddr, ucmd, uwe, uwrdata, urddata, busy, state_cnt);
				
input             clk,rst;

inout   [15:0 ]       data;

output  [12:0 ]       addr;
output  [1 :0 ]       ba;
output                cke;
output                cs_n,ras_n,cas_n,we_n;
output  [1 :0 ]       dqm;

input  [3 :0 ]       dqmi;
output  reg           busy;
output  wire [31:0 ]   urddata;
input   [23:0]	      uaddr;
input   wire          uwe, ucmd;
input   [31:0]        uwrdata;
output reg         [6  :0 ] state_cnt=0;

reg         [15 : 0] dq;                            // SDRAM I/O
reg         [12 : 0] addr;                          // SDRAM Address
reg         [1  : 0] ba;                            // Bank Address
reg                  cke;                           // Synchronous Clock Enable
reg                  cs_n;                          // CS#
reg                  ras_n;                         // RAS#
reg                  cas_n;                         // CAS#
reg                  we_n;                          // WE#
reg          [1 : 0] dqm;                           // I/O Mask
reg                  data_inv_flag;

reg [1:0] nw=0;
reg [15:0] urddata0, urddata1;
assign urddata={urddata1, urddata0};
reg [1:0] ndqmi=0;
reg [15:0] nwrdata=0;
reg [23:0] naddr=0;
reg         [6  :0 ] refreshcnt=0;
wire        [15 : 0] data = dq;

parameter            hi_z = 16'bz;                   // Hi-Z

task active;
    input [1  : 0] bank;
    input [12 : 0] row;
    input [15 : 0] dq_in;
    begin
        cke   <= 1;
        cs_n  <= 0;
        ras_n <= 0;
        cas_n <= 1;
        we_n  <= 1;
        dqm   <= 0;
        ba    <= bank;
        addr  <= row;
        dq    <= dq_in;
    end
endtask

task auto_refresh;
    begin
        cke   <= 1;
        cs_n  <= 0;
        ras_n <= 0;
        cas_n <= 0;
        we_n  <= 1;
        dqm   <= 0;
        ba    <= 0;
        addr  <= 0;
        dq    <= hi_z;
    end
endtask

task burst_term;
    begin
        cke   <= 1;
        cs_n  <= 0;
        ras_n <= 1;
        cas_n <= 1;
        we_n  <= 0;
        dqm   <= 0;
        ba    <= 0;
        addr  <= 0;
        dq    <= hi_z;
    end
endtask

task load_mode_reg;
    input [12 : 0] op_code;
    begin
        cke   <= 1;
        cs_n  <= 0;
        ras_n <= 0;
        cas_n <= 0;
        we_n  <= 0;
        dqm   <= 0;
        ba    <= 0;
        addr  <= op_code [11 : 0];
        dq    <= hi_z;
    end
endtask

task nop;
	input  [1 : 0] dqm_in;
	input [15 : 0] dq_in;
	begin
		cke   <= 1;
		cs_n  <= 0;
		ras_n <= 1;
		cas_n <= 1;
		we_n  <= 1;
		dqm   <= dqm_in;
		ba    <= 0;
		addr  <= 0;
		dq    <= dq_in;
	end
endtask

task precharge_bank_0;
	input  [1 : 0] dqm_in;
	input [15 : 0] dq_in;
	begin
		cke   <= 1;
		cs_n  <= 0;
		ras_n <= 0;
		cas_n <= 1;
		we_n  <= 0;
		dqm   <= dqm_in;
		ba    <= 0;
		addr  <= 0;
		dq    <= dq_in;
	end
endtask

task precharge_bank_1;
    input  [1 : 0] dqm_in;
    input [15 : 0] dq_in;
    begin
        cke   <= 1;
        cs_n  <= 0;
        ras_n <= 0;
        cas_n <= 1;
        we_n  <= 0;
        dqm   <= dqm_in;
        ba    <= 1;
        addr  <= 0;
        dq    <= dq_in;
    end
endtask

task precharge_all_bank;
   input  [1 : 0] dqm_in;
   input [15 : 0] dq_in;
	begin
		cke   <= 1;
		cs_n  <= 0;
		ras_n <= 0;
		cas_n <= 1;
		we_n  <= 0;
		dqm   <= dqm_in;
		ba    <= 0;
		addr  <= 1024;            // A10 <= 1
		dq    <= dq_in;
	end
endtask

task read;
    input [1  : 0] bank;
    input [8  : 0] column;
    input [15 : 0] dq_in;
    input  [1 : 0] dqm_in;
    begin
        cke   <= 1;
        cs_n  <= 0;
        ras_n <= 1;
        cas_n <= 0;
        we_n  <= 1;
        dqm   <= dqm_in;
        ba    <= bank;
        addr  <= column;
        dq    <= dq_in;
    end
endtask

task write;
    input [1  : 0] bank;
    input [8  : 0] column;
    input [15 : 0] dq_in;
    input  [1 : 0] dqm_in;
    begin
        cke   <= 1;
        cs_n  <= 0;
        ras_n <= 1;
        cas_n <= 0;
        we_n  <= 0;
        dqm   <= dqm_in;
        ba    <= bank;
        addr  <= column;
        dq    <= dq_in;
    end
endtask

`define maxrefreshcnt 7'b111_0000
always @ ( posedge clk or negedge rst )
	if( !rst )
		begin
			state_cnt <= 7'b000_0000;
			refreshcnt <= 7'b000_0000;
			busy <= 0;
			urddata0 <= 0;
			urddata1 <= 0;
			// sdram
			cke   <= 0;     
			cs_n  <= 1;     
			ras_n <= 1;     
			cas_n <= 1;     
			we_n  <= 1;     
			dqm   <= 3;
			ba    <= 0;  
			addr  <= 0;
			dq    <= hi_z; 
		end
	else
		begin
			refreshcnt <= refreshcnt + 1;
			state_cnt <= state_cnt + 1 ;
			case( state_cnt )
				'd1 : nop (0, hi_z);                     //0-8 Nop                               
				'd9 : precharge_all_bank(0, hi_z);       //9 Precharge ALL Bank                  
				'd10: nop (0, hi_z);                     //10-11 Nop, tRP's minimum value is 20ns                             
				'd12: auto_refresh;                      //12 Auto Refresh                       
				'd13: nop (0, hi_z);                     //13-20 Nop, tRFC's minimum value is 66ns                             
				'd21: auto_refresh;                      //21 Auto Refresh                       
				'd22: nop (0, hi_z);                     //22-29 Nop, tRFC's minimum value is 66ns                             
				'd30: load_mode_reg (547);               //30 Load Mode: Lat <= 2, BL <= 8, Seq    
				'd31: nop (0, hi_z);                     //31 Nop, 2tCLK                                
				'd32: begin
			              if(refreshcnt >= `maxrefreshcnt) begin
					refreshcnt <= 'd0;
					state_cnt <= 'd91;
				      end else if(nw == 1) begin
                                                naddr <= naddr + 1;
                                                nwrdata <= uwrdata[31:16];
                                                ndqmi <= dqmi[3:2];
                                                state_cnt <= 'd33;
				      end else if (ucmd) begin
					busy <= 1;
					naddr <= uaddr >> 1;
					ndqmi <= dqmi[1:0];
					nw <= 0;
					if(uwe) begin
						nwrdata <= uwrdata[15:0];
						state_cnt <= 'd33;
					end
					else 
						state_cnt <= 'd50;
				      end else
					state_cnt <= 'd32;
				end
				// write
				'd33: active (naddr[23:22], naddr[21:9], hi_z);               //33 Active: Bank <= uaddr[23:22], Row <= uaddr[21:9]
				'd34: nop (0, hi_z);                     //34-35 Nop                             
				'd36: write  (naddr[23:22], naddr[8:0], nwrdata, ndqmi);     //36 Write : Bank <= , Col <= uaddr[8:0], Dqm <= 0 
				'd37: nop (0, hi_z);                     //37 Nop                                
				'd38: nop (0, hi_z);                     //38 Nop                                
				'd39: nop (0, hi_z);                     //39-40 Nop                             
				'd40: begin
					nw <= nw + 1;
					state_cnt <= 'd67;
				end

				// read
				'd50: active (naddr[23:22], naddr[21:9], hi_z);               //50 Active: Bank <= uaddr[23:22], Row <= uaddr[21:9]
				'd51: nop (0, hi_z);                     //51-52 Nop  
				'd53: read   (naddr[23:22], naddr[8:0], hi_z, ndqmi);          //53 Read                                
				'd54: nop (0, hi_z);                     //54 Nop                                
				'd55: nop (0, hi_z);                     //55 Nop
				'd56: urddata0 <= data;
				'd57: urddata1 <= data;
				'd58: state_cnt <= 'd67;
				
				// precharge
				'd67: precharge_all_bank(0, hi_z);       //9 Precharge ALL Bank
				'd68: nop (0, hi_z);                  //10-11 Nop, tRP's minimum value is 20ns
				'd69: begin
						state_cnt <= 'd32;
						busy <= 0;
				end

				'd91: auto_refresh;                      //91 Auto Refresh                       
                                'd92: nop (0, hi_z);                     //92-99 Nop, tRFC's minimum value is 66ns
				'd99: state_cnt <= 'd32;
			endcase
		end

endmodule
