//
// Created by maj3 on 18.04.2020.
//

#ifndef OPENGLTEST_BMP_H
#define OPENGLTEST_BMP_H

#include <stdint.h>
#include "windowsVal.h"

typedef uint8_t  BYTE;
typedef uint32_t DWORD;
typedef int32_t  LONG;
typedef uint16_t WORD;
typedef int HANDLE;
typedef const char* LPCSTR;
typedef char TCHAR;

#pragma pack(push,2)
typedef struct tagBITMAPFILEHEADER {
    WORD	bfType;
    DWORD	bfSize;
    WORD	bfReserved1;
    WORD	bfReserved2;
    DWORD	bfOffBits;
} BITMAPFILEHEADER,*LPBITMAPFILEHEADER,*PBITMAPFILEHEADER;
#pragma pack(pop)

typedef struct tagBITMAPINFOHEADER{
    DWORD	biSize;
    LONG	biWidth;
    LONG	biHeight;
    WORD	biPlanes;
    WORD	biBitCount;
    DWORD	biCompression;
    DWORD	biSizeImage;
    LONG	biXPelsPerMeter;
    LONG	biYPelsPerMeter;
    DWORD	biClrUsed;
    DWORD	biClrImportant;
} BITMAPINFOHEADER,*LPBITMAPINFOHEADER,*PBITMAPINFOHEADER;

#pragma pack(push,1)
typedef struct tagRGBTRIPLE {
    BYTE rgbtBlue;
    BYTE rgbtGreen;
    BYTE rgbtRed;
} RGBTRIPLE,*LPRGBTRIPLE;

#pragma pack(pop)

typedef struct _FILETIME { // ft
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
} FILETIME;

typedef struct _WIN32_FIND_DATA { // wfd
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD    nFileSizeHigh;
    DWORD    nFileSizeLow;
    DWORD    dwReserved0;
    DWORD    dwReserved1;
    TCHAR    cFileName[ MAX_PATH ];
    TCHAR    cAlternateFileName[ 14 ];
} WIN32_FIND_DATA;

#endif //OPENGLTEST_BMP_H


