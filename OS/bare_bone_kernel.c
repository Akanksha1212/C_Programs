/**
 * Copyright (c) 2020, Florian Büstgens
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     1. Redistributions of source code must retain the above copyright
 *        notice, this list of conditions and the following disclaimer.
 *
 *     2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 *        documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY <copyright holder> ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <copyright holder> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stddef.h>
#include <stdint.h>

// CONST
// A typical VGA Buffer on x86(_64) is a 2 dimensional array of 25x80 entries.
static const unsigned int VGA_W = 80;
static const unsigned int VGA_H = 25;

// VARIABLE
unsigned int tty_row;
unsigned int tty_col;
uint8_t tty_color;
uint16_t *tty_buf;

// ENUMS
enum vga_color {
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
};

// FUNC
unsigned int
_strlen(const char *str)
{
	const char *s;

	for (s = str; *s; ++s)
		;

	return (s - str);
}

static inline uint8_t
_vga_byte_color(enum vga_color fg, enum vga_color bg)
{
	return bg << 4 | fg;
}

static inline uint16_t
_vga_byte(unsigned char ch, uint8_t color)
{
	return (uint16_t)ch | (uint16_t)color << 8;
}

void
_tty_putchar(const char c)
{
	const unsigned int index = tty_row * VGA_W + tty_col;
	tty_buf[index] = _vga_byte(c, tty_color);

	if (++tty_col == VGA_W) {
		tty_col = 0;
		if (++tty_row == VGA_H)
			tty_row = 0;
	}
}

void
_print_k(const char *msg, unsigned int size)
{
	for (unsigned int volatile register i = 0; i < size; ++i)
		_tty_putchar(msg[i]);
}

void
print_k(const char *msg)
{
	_print_k(msg, _strlen(msg));
}

void
_tty_init(void)
{
	tty_row = 0;
	tty_col = 0;
	tty_color = _vga_byte_color(VGA_COLOR_GREEN, VGA_COLOR_BLACK);
	tty_buf = (uint16_t *)0xB8000;

	for (unsigned int volatile register i = 0; i < VGA_H; ++i) {
		for (unsigned int volatile register j = 0; j < VGA_W; ++j) {
			const unsigned int index = i * VGA_W + j;
			tty_buf[index] = _vga_byte(' ', tty_color);
		}
	}
}

void
_kernel_start(void)
{
	_tty_init();

	print_k(
	    "Hello, world! This is a really tiny kernel. It just can print stuff on the vga buffer.");
}

// In order to boot this kernel, you need to compile the following code and glue
// it with a linker script infront of the kernel code.

//;; CONST ==++
//	MBALIGN equ 1 << 0 	    ; aligning loaded modules
//	MEMINFO equ 1 << 1	    ; memory mapping
//	FLAGS equ MBALIGN | MEMINFO ; Multiboot Flagfield
//	MAGIC equ 0x1BADB002	    ; Multiboot magic number
//	CRC equ -(MAGIC + FLAGS)    ; Multiboot Checksum
//;; CONST ==++

//;; HEADER ==++
//	; This is our Multiboot header.
// section .multiboot
// align 4
//	dd MAGIC
//	dd FLAGS
//	dd CRC
//;; HEADER ==++

//;; BSS ==++
//	; Align our stack.
// section .bss
// align 16
// stack_bottom:
//	resb 4096 * 4 		; 16 KiB
// stack_top:
//;; BSS ==++

//;; TEXT ==++
// section .text
// global _start:function (_start.end - _start)
//_start:
//	mov esp, stack_top	; Prepare Stackpointer
// extern _kernel_start
//	call _kernel_start
//	cli			; Disable interrupts, preparing to go down.
//.hang:
//	hlt			; Infinite loop
//	jmp .hang
//.end:				; Bye
//;; TEXT ==++
