// author Laurentiu-Cristian Duca, 20231028-1235
// SPDX-License-Identifier: MIT

module clkdivider(clk, reset_n, n, clkdiv);

input wire clk, reset_n;
input wire [20:0] n;
output reg clkdiv=0;

reg [20:0] cnt=0;

always @(posedge clk) begin
	if(cnt < n) begin
		cnt <= cnt+1;
		clkdiv <= 0;
	end else begin
		cnt <= 0;
		clkdiv <= 1;
	end
end
endmodule
