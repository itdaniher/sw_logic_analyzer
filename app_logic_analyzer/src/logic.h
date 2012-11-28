// Copyright (c) 2011, XMOS Ltd, All rights reserved
// This software is freely distributable under a derivative of the
// University of Illinois/NCSA Open Source License posted in
// LICENSE.txt and at <http://github.xcore.com/>

#include <syscall.h>
#include <platform.h>
#include <xs1.h>
#include <xclib.h>
#include <print.h>
#include <stdio.h>

#include "xud.h"
#include "usb.h"

/* Endpoint type tables */
XUD_EpType epTypeTableOut[2] =   {XUD_EPTYPE_CTL, 
                                  XUD_EPTYPE_BUL, 
}; 

XUD_EpType epTypeTableIn[3] = {   XUD_EPTYPE_CTL,
                                  XUD_EPTYPE_BUL, 
                                  XUD_EPTYPE_BUL,
};

/* USB Port declarations */
out port p_usb_rst       = XS1_PORT_1I; // XDK PORT_1B, XTR: 1k
clock    clk             = XS1_CLKBLK_3;
clock    clkPins         = XS1_CLKBLK_4;

void Endpoint0(chanend c_ep0_out, chanend c_ep0_in);

#define BUF_WORDS 512  // Buffer length
#define NUM_BUFFERS 16

#define USB_HOST_BUF_WORDS 128
extern unsigned int data_buffer[NUM_BUFFERS][BUF_WORDS/4];
extern unsigned char data_buffer_[NUM_BUFFERS][BUF_WORDS];

unsigned int data_buffer[NUM_BUFFERS][BUF_WORDS/4];
unsigned char data_buffer_[NUM_BUFFERS][BUF_WORDS];

