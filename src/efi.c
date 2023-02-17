#include <efi/efi_lib.h>

EFI_SYSTEM_TABLE* g_ST;

VOID InitLib(IN EFI_SYSTEM_TABLE* ST)
{
	g_ST = ST;

	g_ST->ConOut->Reset(g_ST->ConOut, TRUE);
	g_ST->ConIn->Reset(g_ST->ConIn, TRUE);
}

VOID PrintString(CHAR16 * String)
{
	g_ST->ConOut->OutputString(g_ST->ConOut, String);
}