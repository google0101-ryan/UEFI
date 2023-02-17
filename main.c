#include <efi/efi_lib.h>

__attribute__((noreturn)) EFI_STATUS EFIAPI efi_main(IN EFI_HANDLE ImageHandle, IN EFI_SYSTEM_TABLE *ST)
{
	InitLib(ST);

	PrintString(L"Hello, world!\n");
	
	for (;;);
}