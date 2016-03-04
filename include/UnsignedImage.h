#pragma once
#include "Image.h"

class UnsignedImage : public Image
{
private:
	unsigned char* m_data;
public:
	UnsignedImage(int w, int h, int n, const void* data);
	UnsignedImage(const UnsignedImage& image);
	UnsignedImage(UnsignedImage&& image);
	UnsignedImage& operator=(const UnsignedImage& image);
	UnsignedImage& operator=(UnsignedImage&& image);
	virtual ~UnsignedImage();

	unsigned char* GetData()const;
	const unsigned char& At(int row, int col, int nth)const;
	unsigned char&At(int row, int col, int nth);
};