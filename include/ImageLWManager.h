#pragma once
#include "Image.h"
#include "UnsignedImage.h"
#include "common/common.h"

#include <cstring>

class ImageLoader
{
	DISALLOW_COPY_AND_ASSIGN(ImageLoader);
public:
	ImageLoader() = default;
	UnsignedImage LoadImage(const std::string& filePath, int req_comp=0);

};

class ImageWriter
{
	DISALLOW_COPY_AND_ASSIGN(ImageWriter);
public:
	ImageWriter() = default;
	int WritePNGImage(const UnsignedImage& image, const std::string& outputPath)const;
};