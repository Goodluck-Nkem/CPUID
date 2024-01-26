.intel_syntax noprefix		# use intel syntax

.global cpuid_data			# make function visibility global

#; Linux x64 parameter passing

#; syscall number: rax
#; system call:  rdi, rsi, rdx, r10, r8, r9
#; sys return: rax

#; user normal call: rdi, rsi, rdx, rcx, r8, r9
#; user normal return: rax(lo), rdx(hi)
#; user float call: xmm0 - xmm7
#; user float return: xmm0(lo), xmm1(hi)

#; Saved: rbx, rbp, rsp, r12, r13, r14, r15
#; volatile: args, return, r10, r11, xmm

.text

.p2align 4					# align section to 16 bytes
.section .text.cpuid_data
cpuid_data:
	mov eax, edi			# loads lower clears upper dword
	mov rcx, rdi			# copy input
	shr rcx, 32				# get ecx from upper dword
	cpuid					# invoke cpuid
	mov [rsi + 0], eax		# load eax
	mov [rsi + 4], ebx		# load ebx
	mov [rsi + 8], ecx		# load ecx
	mov [rsi + 12], edx		# load edx
	ret						# return

.section .note.GNU-stack	# gcc seems to need this section defined

