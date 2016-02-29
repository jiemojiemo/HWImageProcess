#pragma once
#include "Image.h"
#include "common/common.h"
class ImageManager
{
	DISALLOW_COPY_AND_ASSIGN(ImageManager);
public:
	Image&& LoadImageFromFile();
	int WriteImage();
};