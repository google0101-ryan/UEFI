#pragma once

#include <efi/efi_types.h>
#include <efi/efi_tables.h>

VOID InitLib(IN EFI_SYSTEM_TABLE* ST);
VOID PrintString(CHAR16 *String);