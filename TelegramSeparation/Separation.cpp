// TelegramSyncDlg.cpp : implementation file
//

#include "Separation.h"
#include <atlstr.h>
#include <cstring>
#include <cstdio>

/*
original test stream 


[03:05] (00097)
D7 20 62 57 F3 3C CC 6B 1A F5 78 4A B4 20 76 8D 2E 6F C1 DC 2A 56 AF 69 3B C9 F3 8F D9 CC 0C 37 22 3C C7 B4 4F F0 E3 BD 
45 C9 E0 E5 60 87 8C 72 2F 94 AF C1 66 A2 6B CD 4A C7 74 A2 E3 5F 4D 93 3E FA 9D 47 E9 FC 50 D1 1A 1E F2 08 B2 EC 17 8D 
1F 3B 6B 82 1B 47 78 0B E2 E3 5B 03 23 69 41 7F FE 
[03:05] (00036)
72 23 CC 7B 44 FF 0E 3B D4 5C 9E 0E 56 08 78 C7 22 F9 4A FC 16 6A 26 BC D4 AC 77 4A 2E 35 F4 D9 33 EF A9 D4 
[03:05] (00094)
7E 9F C5 0D 11 A1 EF 20 8B 2E C1 78 D1 F3 B6 B8 21 B4 77 80 BE 2E 35 B0 32 36 94 1F 18 88 0A AD 46 11 B8 7F 46 52 10 44 
09 83 0C 2B 4A C2 6E 62 E1 2A 69 C4 0F 90 A8 55 68 9D 40 43 BA E4 0C 4A FE 67 99 8D 63 5E AF 09 56 84 0E D1 A5 CD F8 3B 
85 4A D5 ED 27 79 3E 71 FB 39 81 86 E4 47 
[03:05] (00127)
98 F6 89 FE 1C 77 A8 B9 3C 1C AC 10 F1 8E 45 F2 95 F8 2C D4 4D 79 A9 58 EE 94 5C 6B E9 B2 67 DF 53 A8 FD 3F 8A 1A 23 43 
DE 41 16 5D 82 F1 A3 E7 6D 70 43 68 EF 01 7C 5C 6B 60 64 6D 28 3E 31 10 15 5A 8C 23 70 FE 8C A4 20 88 13 06 18 56 95 84 
DC C5 C2 54 D3 88 1F 21 50 AA D1 3A 80 87 75 C8 18 95 FC CF 33 1A C6 BD 5E 12 AD 08 1D A3 4B 9B F0 77 0A 95 AB DA 4E F2 
7C E3 F6 73 03 0D C8 
[03:06] (00064)
8F 31 ED 13 FC 38 EF 51 72 78 39 58 21 E3 1C 8B E5 2B F0 59 A8 9A F3 52 B1 DD 28 B8 D7 D3 64 CF BE A7 51 FA 7F 14 34 46 
87 BC 82 2C BB 05 E3 47 CE DA E0 86 D1 DE 02 F8 B8 D6 C0 C8 DA 50 7C 62 
[03:06] (00065)
20 2A B5 18 46 E1 FD 19 48 41 10 26 0C 30 AD 2B 09 B9 8B 84 A9 A7 10 3E 42 A1 55 A2 75 01 0E EB 90 31 2B F9 9E 66 35 8D 
7A BC 25 5A 10 3B 46 97 37 E0 EE 15 2B 57 B4 9D E4 F9 C7 EC E6 06 1B 91 1E 
[03:06] ~ Count:[481]
[03:06] LongTg = 2B.4A.C2.6E.62.E1.2A.69.
[03:06]          C4.0F.90.A8.55.68.9D.40.
[03:06]          43.BA.E4.0C.4A.FE.67.99.
[03:06]          8D.63.5E.AF.09.56.84.0E.
[03:06]          D1.A5.CD.F8.3B.85.4A.D5.
[03:06]          ED.27.79.3E.71.FB.39.81.
[03:06]          86.E4.47.98.F6.89.FE.1C.
[03:06]          77.A8.B9.3C.1C.AC.10.F1.
[03:06]          8E.45.F2.95.F8.2C.D4.4D.
[03:06]          79.A9.58.EE.94.5C.6B.E9.
[03:06]          B2.67.DF.53.A8.FD.3F.8A.
[03:06]          1A.23.43.DE.41.16.5D.82.
[03:06]          F1.A3.E7.6D.70.43.68.EF.
[03:06]          01.7C.5C.6B.60.64.6D.28.
[03:06]          3E.31.10.15.5A.8C.23.70.
[03:06]          FE.8C.A4.20.88.13.06.18.
[03:06]          
*/


BYTE upLoadstream[480] = {
	0xD7,0x20,0x62,0x57,0xF3,0x3C,0xCC,0x6B,0x1A,0xF5,0x78,0x4A,0xB4,0x20,0x76,0x8D,    //1
	0x2E,0x6F,0xC1,0xDC,0x2A,0x56,0xAF,0x69,0x3B,0xC9,0xF3,0x8F,0xD9,0xCC,0x0C,0x37,    //2
	0x22,0x3C,0xC7,0xB4,0x4F,0xF0,0xE3,0xBD,0x45,0xC9,0xE0,0xE5,0x60,0x87,0x8C,0x72,    //3
	0x2F,0x94,0xAF,0xC1,0x66,0xA2,0x6B,0xCD,0x4A,0xC7,0x74,0xA2,0xE3,0x5F,0x4D,0x93,    //4
	0x3E,0xFA,0x9D,0x47,0xE9,0xFC,0x50,0xD1,0x1A,0x1E,0xF2,0x08,0xB2,0xEC,0x17,0x8D,    //5 
	0x1F,0x3B,0x6B,0x82,0x1B,0x47,0x78,0x0B,0xE2,0xE3,0x5B,0x03,0x23,0x69,0x41,0x7F,    //6 
	0xFE,0x72,0x23,0xCC,0x7B,0x44,0xFF,0x0E,0x3B,0xD4,0x5C,0x9E,0x0E,0x56,0x08,0x78,    //7
	0xC7,0x22,0xF9,0x4A,0xFC,0x16,0x6A,0x26,0xBC,0xD4,0xAC,0x77,0x4A,0x2E,0x35,0xF4,    //8
	0xD9,0x33,0xEF,0xA9,0xD4,0x7E,0x9F,0xC5,0x0D,0x11,0xA1,0xEF,0x20,0x8B,0x2E,0xC1,    //9 
	0x78,0xD1,0xF3,0xB6,0xB8,0x21,0xB4,0x77,0x80,0xBE,0x2E,0x35,0xB0,0x32,0x36,0x94,    //10
	0x1F,0x18,0x88,0x0A,0xAD,0x46,0x11,0xB8,0x7F,0x46,0x52,0x10,0x44,0x09,0x83,0x0C,    //11
	0x2B,0x4A,0xC2,0x6E,0x62,0xE1,0x2A,0x69,0xC4,0x0F,0x90,0xA8,0x55,0x68,0x9D,0x40,    //12 
	0x43,0xBA,0xE4,0x0C,0x4A,0xFE,0x67,0x99,0x8D,0x63,0x5E,0xAF,0x09,0x56,0x84,0x0E,    //13 
	0xD1,0xA5,0xCD,0xF8,0x3B,0x85,0x4A,0xD5,0xED,0x27,0x79,0x3E,0x71,0xFB,0x39,0x81,    //14 
	0x86,0xE4,0x47,0x98,0xF6,0x89,0xFE,0x1C,0x77,0xA8,0xB9,0x3C,0x1C,0xAC,0x10,0xF1,    //15 
	0x8E,0x45,0xF2,0x95,0xF8,0x2C,0xD4,0x4D,0x79,0xA9,0x58,0xEE,0x94,0x5C,0x6B,0xE9,    //16 
	0xB2,0x67,0xDF,0x53,0xA8,0xFD,0x3F,0x8A,0x1A,0x23,0x43,0xDE,0x41,0x16,0x5D,0x82,    //17 
	0xF1,0xA3,0xE7,0x6D,0x70,0x43,0x68,0xEF,0x01,0x7C,0x5C,0x6B,0x60,0x64,0x6D,0x28,    //18 
	0x3E,0x31,0x10,0x15,0x5A,0x8C,0x23,0x70,0xFE,0x8C,0xA4,0x20,0x88,0x13,0x06,0x18,    //19 
	0x56,0x95,0x84,0xDC,0xC5,0xC2,0x54,0xD3,0x88,0x1F,0x21,0x50,0xAA,0xD1,0x3A,0x80,    //20 
	0x87,0x75,0xC8,0x18,0x95,0xFC,0xCF,0x33,0x1A,0xC6,0xBD,0x5E,0x12,0xAD,0x08,0x1D,    //21 
	0xA3,0x4B,0x9B,0xF0,0x77,0x0A,0x95,0xAB,0xDA,0x4E,0xF2,0x7C,0xE3,0xF6,0x73,0x03,    //22 
	0x0D,0xC8,0x8F,0x31,0xED,0x13,0xFC,0x38,0xEF,0x51,0x72,0x78,0x39,0x58,0x21,0xE3,    //23 
	0x1C,0x8B,0xE5,0x2B,0xF0,0x59,0xA8,0x9A,0xF3,0x52,0xB1,0xDD,0x28,0xB8,0xD7,0xD3,    //24 
	0x64,0xCF,0xBE,0xA7,0x51,0xFA,0x7F,0x14,0x34,0x46,0x87,0xBC,0x82,0x2C,0xBB,0x05,    //25 
	0xE3,0x47,0xCE,0xDA,0xE0,0x86,0xD1,0xDE,0x02,0xF8,0xB8,0xD6,0xC0,0xC8,0xDA,0x50,    //26 
	0x7C,0x62,0x20,0x2A,0xB5,0x18,0x46,0xE1,0xFD,0x19,0x48,0x41,0x10,0x26,0x0C,0x30,    //27 
	0xAD,0x2B,0x09,0xB9,0x8B,0x84,0xA9,0xA7,0x10,0x3E,0x42,0xA1,0x55,0xA2,0x75,0x01,    //28 
	0x0E,0xEB,0x90,0x31,0x2B,0xF9,0x9E,0x66,0x35,0x8D,0x7A,0xBC,0x25,0x5A,0x10,0x3B,    //29 
	0x46,0x97,0x37,0xE0,0xEE,0x15,0x2B,0x57,0xB4,0x9D,0xE4,0xF9,0xC7,0xEC,0xE6,0x06     //30 
};
//0x1B 0x91 0x1E 

typedef  unsigned char   UINT08;  
typedef  unsigned short  UINT16;
typedef  unsigned int    UINT32;

#define		SHORTSIZ	341+1
#define		TLGSIZ		1024

char	strorg[TLGSIZ];
char	strglx[TLGSIZ];
char	strrem[TLGSIZ];
char	strgsx[TLGSIZ];
char	strflx[TLGSIZ];
char	strsrc[TLGSIZ];
char	strfsx[TLGSIZ];

int  asequence; 

void CheckSerialIncomeTelegram(char *src, int clen, char *msg)
{
	int i, j, n, sb, esb;

	char temp[2048], stmp[2048], ssbit[2048];
	int m = 0;

	if(clen > 1024 ){
		return;
		//clen = 1024;
	}
	//
	//	See subset36-clause 4.3.4.1.2 /Paritycheck bits/g(x).					
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	memset( stmp, NULL, sizeof(stmp ));
	memcpy(stmp, src, clen );                         // clen ==> 480 BYTE

	// *(stemp + 142 ) 까지 Reverse bit 값을 ssbit에 삽입.
	MakeString2ReverseBits( stmp, ssbit, 1144 );  // [1023+121]stemp[143Byte]-> -(bit change)-> ssBits[1144Byte(0,1)]   ::   [받은데이터의 약143Byte]

	memset( strorg, '0', 1024);
	//TRACE("\r\n==================================================\r\n~ Count:[%d]\r\n", clen);

	for(n = 0; n < clen-122; n++){      //  [480-122=358]
		DivideBitstream2s( ssbit+n, strgsx, strrem );  // ssbit+(max[358+342]); ssbit와 strgsx을 비교 후 값을 sttrem에 삽입. [받은데이터의 약 88Byte]
		i = Iszero(strrem, 76);         // *(strrem +75)이하의 값중 '1'이 있으면 1, 없으면 0
		if( i == 0 ){                   // '1'이 없으면.
			Synchronisations( ssbit, &sb, &esb, n );
			if( asequence == 0 ) {
				j = DisplayBits("Short.", strorg+(TLGSIZ-120), 120, msg);
				if(j == 9){
					n+= 11;
					continue;
				}
			}
			//TRACE( "return short!!!\n" );
			break;
		}
	}

	for(n = 0; n < clen-122; n++){                 //  [480-122=358]
		DivideBitstream2(ssbit, strglx,  strrem);  // ssbit+(1024]); ssbit와 strgsx을 비교 후 값을 sttrem에 삽입. [받은데이터의  128Byte] 
		i = Iszero(strrem, 76);                    // *(strrem +75)이하의 값중 '1'이 있으면 1, 없으면 0 [ 10Byte ]
		if(i == 0){
			Synchronisation(ssbit, &sb, &esb);
			//SendCommand2Loader("ReceiveOk\n");
			if(asequence == 0){
				DisplayBits("LongTg", strorg, 1024, msg);
				//TRACE("==================================================\r\n");
			}
			return;
		}
		memcpy(temp, src+n, clen);							    // ???  
		MakeString2ReverseBits(temp, ssbit, 1100 );	            // 1023 + 77
	}
}



void MakeString2ReverseBits(char *hexs, char *bits, int max)
{
	int	i,j,bytelen,n=0;											// Convert Hexstring to bit stream.

	memset(bits, '0', max);                                     //                     '0' = 0x30   bytelen =  
	bytelen = (max+7)/8;										// Last 1bit -> 1byte. 
	for(i = bytelen-1; i >= 0; i--){                            // hexs = 0x12 => 00010010
		for( j = 0; j < 8; j++ ){
			if( (BYTE)hexs[i] & (0x01 << j ) ) bits[n++] = '1'; 
			else                               bits[n++] = '0';
			if( n > max) return;
		}			
	}
}

void DivideBitstream2s(char *dividend, char *divisor, char *remainder)
{
	int msb1,msb2;
	int i, Max;
	char temp[SHORTSIZ];

	memcpy(temp, dividend, SHORTSIZ);  // copy (temp + 342)+342
	msb1 = IsMSBOne(temp, SHORTSIZ);   //    temp 중 값이 1인 마지막 위치 +1              0010001[7] ->max = 7
	msb2 = IsMSBOne(divisor, SHORTSIZ);// divisor 중 값이 1인 마지막 위치 +1   [76]<--Pix       
	if(msb1 == 0 || msb2 == 0) return; // 값이 1이 둘다 없다면 리턴.
	Max = msb1;                               
	for(i = 0; i < Max; i++){                       //   
		if(msb1 < msb2) break;                      //   msb1 < 76
		if(temp[msb1-1] == '1' ){                   //                       
			submodulo2(temp, divisor, msb1, msb2);  //   temp문자열에서 [ msb1]~[msb1-76]  same = '0' diff = '1'
		}
		msb1--;                                     //              
	}
	memcpy(remainder, temp, SHORTSIZ); // 변경된 temp값을 remainder에 복사.
}



//  값이 1 인경우 마지막 1의위치+1을 리턴.   
int IsMSBOne(char *e, int n)
{
	int i,msb = -1;

	for(i = 0; i < n; i++){
		if(*e++ == '1') msb = i;
	}
	return msb+1;
}

void submodulo2(char *divid, char *divis, int n1, int n2)
{
	int i;

	for(i = n2-1; i >= 0; i--){  // divis의 마지막 1 위치 ( n1->down > n2->pix ) 
		n1--;                   
		(divid[n1] != divis[i]) ? divid[n1] = '1' : divid[n1] = '0';  // 다르면 '1', 같으면 '0'
	}
}

void Synchronisation(char *s, int *psb, int *pesb)
{
	int a,b,i;
	char synstr[TLGSIZ],savglx[TLGSIZ],savtmp[TLGSIZ],*tp;

	memcpy(synstr, s, TLGSIZ);								// synstr <-strorg.
	memcpy(savglx, strglx, TLGSIZ);

	ShiftRightBitstream((BYTE*)synstr, TLGSIZ, '0');        // symstr << 1 마지막 0
	DivideBitstream2(synstr, strflx,  strrem);
	a = Asc2Int(strrem+9, 10);

	memcpy(savglx, strglx, TLGSIZ);
	for(i = 0; i < 1023; i++){
		DivideBitstream2(savglx, strflx, strrem);
		b = Asc2Int(strrem+9, 10);
		if(a == b) break;
		ShiftLeftBitsRotate((BYTE*)savglx, TLGSIZ, 1);
	}
	if(a && a == b){
		*psb = i;
		tp = s+i;
		a = 1023-i;
		memcpy(savtmp+a, s, 1024-a);
		memcpy(savtmp+1, s+ 1024-a, a);
		memcpy(strorg, savtmp, TLGSIZ);
		memcpy(strsrc, savtmp, TLGSIZ);
		ShiftRightBitstream((BYTE*)strsrc, TLGSIZ, '0');	
	}
}

void Synchronisations(char *s, int *psb, int *pesb, int n)
{
	int a,b,i;
	char synstr[TLGSIZ],savglx[TLGSIZ],savtmp[TLGSIZ],*tp;

	memcpy(synstr, s, SHORTSIZ);								// synstr <-strorg.
	memcpy(savglx, strgsx, SHORTSIZ);

	ShiftRightBitstream((BYTE*)synstr, SHORTSIZ, '0');  // symstr [342]  << 1 마지막 0 
	DivideBitstream2(synstr, strfsx, strrem);           // synstr+(max[1024]); synstr와 strfsx을 비교 후 값을 sttrem에 삽입.        
	a = Asc2Int(strrem+9, 10);                          // strrem+(0~9) : 역순 bit값을 10진수로. 

	for(i = 0; i < 341; i++){
		DivideBitstream2(savglx, strfsx, strrem);       // synstr+(max[1024]); synstr와 strfsx을 비교 후 값을 sttrem에 삽입. 
		b = Asc2Int(strrem+9, 10);
		if(a == b) break;
		ShiftLeftBitsRotate((BYTE*)savglx, SHORTSIZ, 1);   // symstr [342]  >> 1  처음(마지막거) 
	}
	if(a && a == b){
		*psb = i;
		tp = s+i;
		a = 341-i;
		memcpy(savtmp+a, s, SHORTSIZ-a);
		memcpy(savtmp+1, s+ SHORTSIZ-a, a);
		memcpy(strorg+341*2, savtmp, SHORTSIZ);
		memcpy(strsrc+341*2, savtmp, SHORTSIZ);
		ShiftRightBitstream((BYTE*)strsrc, SHORTSIZ, '0');	
	}
}

void ShiftRightBitstream(BYTE *s, int len, char last)
{
	char temp[TLGSIZ];

	memcpy(temp, s, len);
	memcpy(s, temp+1, len-1);
	s[len-1] = last;
}

void ShiftLeftBitsRotate(BYTE *s, int len, int n)
{
	char c, temp[2048];
	int i;

	for(i = 0; i < n; i++){
		c = s[len-1];
		memcpy(temp, s, len);             //1234567890
		memcpy(s+1, temp, len-1);         //?123456789
		s[0] = c;                         //9123456789
	}
}


void DivideBitstream2(char* dividend,	 char* divisor, char* remainder )
{
	int msb1,msb2;
	int i, Max;
	char temp[TLGSIZ];  // 1024

	memcpy(temp, dividend, TLGSIZ);    // copy ( temp ) + 1024 ==>
	msb1 = IsMSBOne(temp, TLGSIZ);     //    temp 중 값이 1인 마지막 위치 +1              0010001[7] ->max = 7
	msb2 = IsMSBOne(divisor, TLGSIZ);  // divisor 중 값이 1인 마지막 위치 +1   [76]<--Pix  
	if(msb1 == 0 || msb2 == 0) return;
	Max = msb1;
	for(i = 0; i < Max; i++){   
		if(msb1 < msb2 ) break;
		if(temp[msb1-1] == '1'){
			submodulo2(temp, divisor, msb1, msb2);
		}
		msb1--;
	}
	memcpy( remainder, temp, TLGSIZ );
}  /* unsigned_divide */

// 비트문자열(10010101)을 받아서 int형으로 리턴.
int Asc2Int(char *s, int n)
{
	int k,j;

	k = 0;
	for(j = 0; j < n; j++){       //문자열 개수 만큼.
		k<<= 1;                  // K shift(2진 자리수 올리기)
		if(*s-- == '1') k+= 1;   // 문자열에 1이 있다면 K값 증가( 문자열 역순으로 읽어드린다) 
	}

	return k;
}


int DisplayBits(char *msg, void *b, int blen, char *ret_msg)
{
	int i, j, k, c, n=0, Flag = 1;
	int sp, np, bytes, slen, zero = 0;					// Display bitstream to HEX.
	char sz[512];
	char *cb;
	int  tp = 0;
	//char tz[512];
	UINT08 cp[512];
	CString Data, sub;
	memset( &cp, NULL, sizeof( cp ) );

	cb = (char*)b;
	sp = sprintf(sz, "%s = ", msg); 
	np = sp;
	slen = sp;
	bytes = (blen+7)/8;          // 1Bit일 경우도 1byte로 처리..
	k = bytes*8;

	for(i = 0; i < bytes; i++){
		c = 0;
		for(j = 0; j < 8; j++){	 // Make 1char.
			c <<= 1;                         // shift <<
			if(cb[--k] == '1') c |= 1;       // 01010101 01010101 111100XX <-뒤에서 부터..
		}
		sp+= sprintf(sz+sp, "%02X.", c );
		//TRACE("TRACE ---- %s\r\n", sz);
		cp[i] = (UINT08)c;
		if( blen < 150 ){
			if(c == 0 ){
				if( ++zero >= 12 ){             //연속해서 0x00 값이면[12번이상].
					return 9;
				}
			}
		}else{                                  // 0 정보의 리스트 표출 막기 위해. 
			if(c == 0 && i < 8 ){
				zero++;
				if(zero >= 8 ) Flag = 0;
			}
		}
		n++;
		if(n == 8 ){											// New line. [16개까지 처리했으면]	
			n = 0;
			sz[sp] = 0;
			if( Flag ) {
				strcat(ret_msg, sz);//TRACE("%s\r\n", sz);		
				strcat(ret_msg, "\n");
			}
			for(j = 0; j < np; j++) sz[j] = ' ';				// Allinement text.
			sp = np;
		}
	}
	sz[sp] = 0;			// 1,2,3,4,5 4,5,6,7,8
	return 0;
}


int Iszero(char *s, int n)
{
	char *cp;

	cp = s;
	while(n--){
		if(*cp++ == '1') return 1;
	}
	return 0;
}


void MakeflxStream(char *s, int n)
{
	CString Data = "11111011011";
	memset( s, '0', n );
	//	s[10]='1'; s[9]='1'; s[7]='1'; s[6]='1'; s[4]='1'; s[3]='1'; s[2]='1'; s[1]='1'; s[0] = '1';
	memcpy( s, (LPCSTR)CT2A(Data), Data.GetLength() );
}

void MakefsxStream(char *s, int n)
{
	CString Data = "11010101101";
	memset(s, '0', n);
	//		s[10]='1'; s[8]='1'; s[7]='1'; s[5]='1'; s[3]='1'; s[1]='1'; s[0] = '1';
	memcpy( s, (LPCSTR)CT2A(Data), Data.GetLength() );
}

void MakeGlxStream(char *s, int n)
{ 
	//                0         1         2         3         4         5         6         7  
	//                0123456789012345678901234567890123456789012345678901234567890123456789012345
	CString Data = "1100100001011101110001001010101101110100010111100101100111001110000100011101";
	memset(s, '0', n);
	memcpy( s, (LPCSTR)CT2A(Data), Data.GetLength() );
	//		s[75]='1'; s[73]='1'; s[72]='1'; s[71]='1'; 
	//		s[67]='1'; s[62]='1'; s[61]='1'; s[60]='1'; 
	//		s[57]='1'; s[56]='1'; s[55]='1'; s[52]='1'; s[51]='1';
	//		s[49]='1'; s[46]='1'; s[45]='1'; s[44]='1'; s[43]='1'; s[41]='1'; 
	//		s[37]='1'; s[35]='1'; s[34]='1'; s[33]='1'; s[31]='1'; s[30]='1'; 
	//		s[28]='1'; s[26]='1'; s[24]='1'; s[21]='1'; 
	//		s[17]='1'; s[16]='1'; s[15]='1'; s[13]='1'; s[12]='1'; s[11]='1'; 
	//		s[ 9]='1'; s[ 4]='1'; s[ 1]='1'; s[ 0]='1';
}


void MakeGsxStream(char *s, int n)
{
	//                0         1         2         3         4         5         6         7  
	//                0123456789012345678901234567890123456789012345678901234567890123456789012345
	CString Data = "1101001000111100010100100101001111101111011111110100001100001001111011111001";
	memset( s, '0', n);
	memcpy( s, (LPCSTR)CT2A(Data), Data.GetLength() );
	//		s[75]='1'; s[72]='1'; s[71]='1'; s[70]='1'; 
	//		s[69]='1'; s[68]='1'; s[66]='1'; s[65]='1'; s[64]='1'; s[63]='1'; s[60]='1'; 
	//		s[55]='1'; s[54]='1'; 
	//		s[49]='1'; s[47]='1'; s[46]='1'; s[45]='1'; s[44]='1'; s[43]='1'; s[42]='1'; s[41]='1'; 
	//		s[39]='1'; s[38]='1'; s[37]='1'; s[36]='1'; s[34]='1'; s[33]='1'; s[32]='1'; s[31]='1'; s[30]='1'; 
	//		s[27]='1'; s[25]='1'; s[22]='1';  
	//		s[19]='1'; s[17]='1'; s[13]='1'; s[12]='1'; s[11]='1';s[10]='1';  
	//		s[ 6]='1'; s[ 3]='1'; s[ 1]='1'; s[ 0]='1';
}


void MakegxxStream()
{
	//
	//  Computing the CheckBits				
	//	make f(x)g(x) by modulo 2							// 4.3.2.4
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~
	MakeflxStream(strflx, TLGSIZ);
	MakefsxStream(strfsx, TLGSIZ);
	MakeGlxStream(strglx, TLGSIZ);
	MakeGsxStream(strgsx, TLGSIZ);
}




/*




*/
char* Separate(char* src, int clen) 
{
	char result[1000];
	strcpy(result, "");
	MakegxxStream();
	CheckSerialIncomeTelegram( src, 480, result);
	return result;
}
