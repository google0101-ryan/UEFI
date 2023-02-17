x86_64-w64-mingw32-gcc -ffreestanding -c -o efi.o src/efi.c  -I ./include
x86_64-w64-mingw32-gcc -ffreestanding -c -o main.o main.c  -I ./include
x86_64-w64-mingw32-gcc -nostdlib -Wl,-dll -shared -Wl,--subsystem,10 -e efi_main -o BOOTX64.EFI main.o efi.o
sh disk.sh