///////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2023 Xilinx, Inc.
// All Rights Reserved
///////////////////////////////////////////////////////////////////////////////
//   ____  ____
//  /   /\/   /
// /___/  \  /    Vendor     : Xilinx
// \   \   \/     Version    : 14.7
//  \   \         Application: Xilinx CORE Generator
//  /   /         Filename   : cs_vio.v
// /___/   /\     Timestamp  : Fri Aug 11 07:52:11 UTC 2023
// \   \  /  \
//  \___\/\___\
//
// Design Name: Verilog Synthesis Wrapper
///////////////////////////////////////////////////////////////////////////////
// This wrapper is used to integrate with Project Navigator and PlanAhead

`timescale 1ns/1ps

module cs_vio(
    CONTROL,
    ASYNC_OUT) /* synthesis syn_black_box syn_noprune=1 */;


inout [35 : 0] CONTROL;
output [7 : 0] ASYNC_OUT;

endmodule
