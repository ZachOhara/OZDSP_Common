#ifndef  __SCALED_BITMAP_H__
#define __SCALED_BITMAP_H__

#include "IPlug_include_in_plug_hdr.h"

#include <cmath>

class ScaledBitmap
{
public:
	ScaledBitmap(int width, int height, double scaleFactor = 4.0);
	~ScaledBitmap();

	void Erase();
	IBitmap& GetIBitmap();

	// Drawing methods
	void BucketFill(int color);
	void FillCircle(int x0, int y0, int radius, int color);

//private:
	const int mOutputWidthPx;
	const int mOutputHeightPx;
	const int mWidthPx;
	const int mHeightPx;
	const double mScaleFactor;

	LICE_pixel* mPixelData;
	LICE_pixel* mOutputData;
	LICE_WrapperBitmap mWrapperBitmap;
	IBitmap mOutputBitmap;

	void ResizeImage();

	void AllocateArrays();
	void DeleteArrays();

	inline int ImageSize();
	inline int Index(int x, int y);
	inline int OutputIndex(int x, int y);
};

#endif // ! __SCALED_BITMAP_H__