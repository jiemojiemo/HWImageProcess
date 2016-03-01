#pragma once
#include "Image.h"
#include "common/common.h"

#include <cstring>
class ImageLWManager
{
	DISALLOW_COPY_AND_ASSIGN(ImageLWManager);
public:
	ImageLWManager() = default;
	Image LoadImage(const std::string& filePath, int req_comp=0);
	int WritePNGImage(const Image& image, const std::string& outputPath);
};