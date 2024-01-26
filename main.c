#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* gets eax, ebx, ecx, edx value, inputs eax(lo), ecx(hi) */
extern void cpuid_data(uint64_t fn, unsigned reg_copy[]);

#define I_EAX 0
#define I_EBX 1
#define I_ECX 2
#define I_EDX 3

int main()
{
	unsigned reg_copy[4];

	/* func0 */
	puts("\n[FUNC0]");
	cpuid_data(0, reg_copy);
	printf("\nHighest func value: %u\n", reg_copy[I_EAX]);
	printf("Vendor string: ");
	for(int i = 0; i < 4; i++)
		putchar(((char*)&reg_copy[I_EBX])[i]);
	for(int i = 0; i < 4; i++)
		putchar(((char*)&reg_copy[I_EDX])[i]);
	for(int i = 0; i < 4; i++)
		putchar(((char*)&reg_copy[I_ECX])[i]);
	putchar('\n');

	/* func1 */
	puts("\n[FUNC1]");
	cpuid_data(1, reg_copy);
	/* data from ecx */
	puts("\nFew ECX features...");
	if(reg_copy[I_ECX] & (0x1 << 0))
		puts("SSE3");
	if(reg_copy[I_ECX] & (0x1 << 9))
		puts("SSSE3");
	if(reg_copy[I_ECX] & (0x1 << 12))
		puts("FMA");
	if(reg_copy[I_ECX] & (0x1 << 13))
		puts("CMPXCHG16B");
	if(reg_copy[I_ECX] & (0x1 << 19))
		puts("SSE4.1");
	if(reg_copy[I_ECX] & (0x1 << 20))
		puts("SSE4.2");
	if(reg_copy[I_ECX] & (0x1 << 22))
		puts("MOVBE");
	if(reg_copy[I_ECX] & (0x1 << 23))
		puts("POPCNT");
	if(reg_copy[I_ECX] & (0x1 << 25))
		puts("AESNI");
	if(reg_copy[I_ECX] & (0x1 << 28))
		puts("AVX");
	if(reg_copy[I_ECX] & (0x1 << 29))
		puts("F16C");
	if(reg_copy[I_ECX] & (0x1 << 30))
		puts("RDRAND");

	/* data from edx */
	puts("\nFew EDX features...");
	if(reg_copy[I_EDX] & (0x1 << 0))
		puts("FPU");
	if(reg_copy[I_EDX] & (0x1 << 8))
		puts("CX8 (CMPXCHG8B)");
	if(reg_copy[I_EDX] & (0x1 << 11))
		puts("SEP");
	if(reg_copy[I_EDX] & (0x1 << 15))
		puts("CMOV");
	if(reg_copy[I_EDX] & (0x1 << 22))
		puts("ACPI");
	if(reg_copy[I_EDX] & (0x1 << 23))
		puts("MMX");
	if(reg_copy[I_EDX] & (0x1 << 25))
		puts("SSE");
	if(reg_copy[I_EDX] & (0x1 << 26))
		puts("SSE2");

	/* func7 */
	puts("\n[FUNC7]");
	cpuid_data(7, reg_copy);
	/* data from ebx */
	puts("\nFew EBX features...");
	if(reg_copy[I_EBX] & (0x1 << 3))
		puts("BMI1");
	if(reg_copy[I_EBX] & (0x1 << 4))
		puts("HLE");
	if(reg_copy[I_EBX] & (0x1 << 5))
		puts("AVX2");
	if(reg_copy[I_EBX] & (0x1 << 8))
		puts("BMI2");
	if(reg_copy[I_EBX] & (0x1 << 18))
		puts("RDSEED");
	if(reg_copy[I_EBX] & (0x1 << 29))
		puts("SHA");

	return 0;
}

