#pragma once

#include <efi/efi_types.h>

// =================================================
// COMMON
// =================================================

typedef struct
{
	UINT64 Signature;
	UINT32 Revision;
	UINT32 HeaderSize;
	UINT32 CRC32;
	UINT32 Reserved;
} EFI_TABLE_HEADER;

// =================================================
// EFI_SIMPLE_TEXT_INPUT_PROTOCOL
// =================================================

typedef struct _EFI_SIMPLE_TEXT_INPUT_PROTOCOL EFI_SIMPLE_TEXT_INPUT_PROTOCOL;

typedef 
EFI_STATUS 
(EFIAPI *EFI_INPUT_RESET) (
	IN EFI_SIMPLE_TEXT_INPUT_PROTOCOL *This,
	IN BOOLEAN ExtendedVerification
);

typedef struct
{
	UINT16 ScanCode;
	CHAR16 UnicodeChar;
} EFI_INPUT_KEY;

typedef
EFI_STATUS
(EFIAPI *EFI_INPUT_READ_KEY) (
	IN EFI_SIMPLE_TEXT_INPUT_PROTOCOL *This,
	OUT EFI_INPUT_KEY *Key
);

struct _EFI_SIMPLE_TEXT_INPUT_PROTOCOL
{
	EFI_INPUT_RESET Reset;
	EFI_INPUT_READ_KEY ReadKey;
	EFI_EVENT WaitForKey;
};

// =================================================
// EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
// =================================================

typedef struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_RESET) (
	IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
	IN BOOLEAN ExtendedVerification
);

typedef 
EFI_STATUS
(EFIAPI *EFI_TEXT_STRING) (
	IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
	IN CHAR16 *String
);

struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
{
	EFI_TEXT_RESET Reset;
	EFI_TEXT_STRING OutputString;
};

// =================================================
// EFI_SYSTEM_TABLE
// =================================================

typedef struct
{
	EFI_TABLE_HEADER Hdr;
	CHAR16 *FirmwareVendor;
	UINT32 FirmwareRevision;
	EFI_HANDLE ConsoleInHandle;
	EFI_SIMPLE_TEXT_INPUT_PROTOCOL *ConIn;
	EFI_HANDLE ConsoleOutHandle;
	EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *ConOut;
} EFI_SYSTEM_TABLE;