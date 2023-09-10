global start

section .text
bits 32
start:
    mov esp, stack_top

    call check_multiboot ; confirm that we have been loaded by multiboot2
    call check_cpuid ; check for cpuid instruction (provides cpu info)
    call check_long_mode ; check for long mode support

    ; print `OK`
    mov dword [0xb8000], 0x2f4b2f4f
    ; freeze cpu
    hlt

check_multiboot:
    cmp eax, 0x36d76289
    jne .no_multiboot
    ret

.no_multiboot:
    mov al, "M" ; M = multiboot error
    jmp error

check_cpuid:
	pushfd
	pop eax
	mov ecx, eax
	xor eax, 1 << 21
	push eax
	popfd
	pushfd
	pop eax
	push ecx
	popfd
	cmp eax, ecx
	je .no_cpuid
	ret

.no_cpuid:
    mov al, "C"  ; C = cpu error
    jmp error

check_long_mode:
	mov eax, 0x80000000
	cpuid
	cmp eax, 0x80000001
	jb .no_long_mode

	mov eax, 0x80000001
	cpuid
	test edx, 1 << 29
	jz .no_long_mode

	ret

.no_long_mode:
    mov al, "L" ; L = long mode error
    jmp error

error:
    ; print "ERR: X" where X is the error code
    mov dword [0xb8000], 0x4f524f45
    mov dword [0xb8000], 0x4f3a4f52
    mov dword [0xb8000], 0x4f204f20
    mov byte  [0xb8000], al
    hlt

section .bss
stack_bottom:
    resb 4096 * 4 ; reserving 16KB of memory for stack

stack_top:
