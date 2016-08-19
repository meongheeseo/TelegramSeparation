#ifndef SEPARATION_HPP
#define SEPARATION_HPP

typedef unsigned char BYTE; 

extern "C"
{
	__declspec(dllexport) char* __cdecl Separate(char* src, int clen);
	__declspec(dllexport) void __cdecl CheckSerialIncomeTelegram(char *src, int clen, char* msg);
	__declspec(dllexport) void __cdecl MakeString2ReverseBits(char *hexs, char *bits, int max);
	__declspec(dllexport) void __cdecl DivideBitstream2s(char *dividend, char *divisor, char *remainder);
	__declspec(dllexport) int __cdecl IsMSBOne(char *e, int n);
	__declspec(dllexport) void __cdecl submodulo2(char *divid, char *divis, int n1, int n2);
	__declspec(dllexport) void __cdecl Synchronisation(char *s, int *psb, int *pesb);
	__declspec(dllexport) void __cdecl Synchronisations(char *s, int *psb, int *pesb, int n);
	__declspec(dllexport) void __cdecl ShiftRightBitstream(BYTE *s, int len, char last);
	__declspec(dllexport) void __cdecl DivideBitstream2(char* dividend,	 char* divisor, char* remainder );
	__declspec(dllexport) int __cdecl Asc2Int(char *s, int n);
	__declspec(dllexport) void __cdecl ShiftLeftBitsRotate(BYTE *s, int len, int n);
	__declspec(dllexport) int __cdecl DisplayBits(char *msg, void *b, int blen, char *ret_msg);
	__declspec(dllexport) int __cdecl Iszero(char *s, int n);
}

#endif