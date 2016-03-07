#pragma once
#include "UnsignedImage.h"
#include <vector>
namespace HW
{
	std::vector<int> imhist(const UnsignedImage& image, unsigned int n=256);
}