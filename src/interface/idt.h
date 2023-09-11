//
// Created by AaronR92 on 9/11/2023.
//

/*
 * idt.h: Data types and setup for the interrupt descriptor table/IDT
 */

#ifdef __x86_64__
typedef unsigned long long int uword_t;
#else
typedef unsigned int uword_t;
#endif

#include "print.h"

#ifndef AURORAOS_IDT_H
#define AURORAOS_IDT_H

// IDT entry
typedef struct {
    uint16_t    isr_address_low;    // Lower 16bits for isr address
    uint16_t    kernel_cs;          // Code segment for this ISR
	uint8_t	    ist;                // The IST in the TSS that the CPU will load into RSP; set to zero for now
    uint8_t     attributes;         // Type and attributes; Flags
	uint16_t    isr_mid;            // The higher 16bits of the lower 32 bits of the ISR's address
    uint32_t    isr_address_high;   // Upper 32bits of isr address
    uint32_t    reserved;           // Set to 0, reserved by intel
} __attribute__ ((packed)) idt_entry_64_t;

// IDTR layout
typedef struct {
	uint16_t	limit;
	uint64_t	base;
} __attribute__((packed)) idtr_64_t;

idt_entry_64_t idt64[256];     // This is the actual IDT
idtr_64_t idtr64;              // Interrupt descriptor table register instance

// Params could be more than 64 bits, like 128, or lower, like 32
// Interrupt 'frame' to pass to interrupt handlers/ISRs
typedef struct {
    uint64_t eip;
    uint64_t cs;
    uint64_t eflags;
    uint64_t sp;
    uint64_t ss;
} __attribute__((packed)) interrupt_frame_64_t;

// Default exception handler (no error code)
__attribute__ ((interrupt)) void default_exception_handler(interrupt_frame_64_t* interrupt_frame_64) {
    print_str_newline("DEFAULT EXCEPTION HANDLER - NO ERROR");
}

// Default exception handler (with error code)
__attribute__ ((interrupt)) void exception_handler(interrupt_frame_64_t* interrupt_frame_64, uword_t error_code) {
    print_str_newline(&"DEFAULT EXCEPTION HANDLER - ERROR: " [error_code])
}

// Default interrupt handler
__attribute__ ((interrupt)) void default_interrupt_handler(interrupt_frame_64_t* interrupt_frame_64) {
    print_str_newline("DEFAULT INTERRUPT HANDLER - NO ERROR");
}

// Add an ISR to the IDT
void set_idt_desctiptor_64(uint8_t entry_number, void *isr, uint8_t flags) {

}

#endif //AURORAOS_IDT_H
