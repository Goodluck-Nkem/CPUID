build:
	x86_64-linux-gnu-gcc-13 -g -c cpuid_data.s -o cpuid.o
	x86_64-linux-gnu-gcc-13 -g main.c cpuid.o -o x64-cpuid.prog

qemu-run: build
	qemu-x86_64 x64-cpuid.prog

run: build
	./x64-cpuid.prog

clean:
	rm -f $(wildcard *.o) $(wildcard *.prog)

