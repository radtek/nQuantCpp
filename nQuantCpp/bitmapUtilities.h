#pragma once
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

//////////////////////////////////////////////////////////////////////////
//
// GetBitmapHeaderSize
//

ULONG GetBitmapHeaderSize(LPCVOID pDib);


//////////////////////////////////////////////////////////////////////////
//
// GetBitmapLineWidthInBytes
//

ULONG GetBitmapLineWidthInBytes(ULONG nWidthInPixels, ULONG nBitCount);

//////////////////////////////////////////////////////////////////////////
//
// GetBitmapDimensions
//

BOOL GetBitmapDimensions(LPCVOID pDib, UINT *pWidth, UINT *pHeight);


//////////////////////////////////////////////////////////////////////////
//
// GetBitmapSize
//

ULONG GetBitmapSize(LPCVOID pDib);



//////////////////////////////////////////////////////////////////////////
//
// GetBitmapOffsetBits
//

ULONG GetBitmapOffsetBits(LPCVOID pDib);

//////////////////////////////////////////////////////////////////////////
//
// FixBitmapHeight
//

BOOL FixBitmapHeight(PVOID pDib, ULONG nSize, BOOL bTopDown);


//////////////////////////////////////////////////////////////////////////
//
// FillBitmapFileHeader
//

BOOL FillBitmapFileHeader(LPCVOID pDib, PBITMAPFILEHEADER pbmfh);

typedef unsigned short (*DitherFn)(const ColorPalette*, const UINT nMaxColors, const ARGB);

bool dither_image(const ARGB* pixels, const ColorPalette* pPalette, DitherFn ditherFn, const bool& hasSemiTransparency, const int& transparentPixelIndex, const UINT nMaxColors, unsigned short* qPixels, const UINT width, const UINT height);

bool dithering_image(const ARGB* pixels, ColorPalette* pPalette, DitherFn ditherFn, const bool& hasSemiTransparency, const int& transparentPixelIndex, const UINT nMaxColors, ARGB* qPixels, const UINT width, const UINT height);

bool ProcessImagePixels(Bitmap* pDest, const ARGB* qPixels, const bool& hasSemiTransparency, const int& transparentPixelIndex);

bool ProcessImagePixels(Bitmap* pDest, const ColorPalette* pPalette, const unsigned short* qPixels);

bool GrabPixels(Bitmap* pSource, vector<ARGB>& pixels, bool& hasSemiTransparency, int& transparentPixelIndex, ARGB& transparentColor);

inline int GetARGBIndex(const Color& c, const bool& hasSemiTransparency)
{
	if (hasSemiTransparency)
		return (c.GetA() & 0xF0) << 8 | (c.GetR() & 0xF0) << 4 | (c.GetG() & 0xF0) | (c.GetB() >> 4);
	return (c.GetR() & 0xF8) << 8 | (c.GetG() & 0xFC) << 3 | (c.GetB() >> 3);
}

