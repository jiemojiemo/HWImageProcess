#pragma once
#include "Image.h"
#include <vector>
namespace HW
{
	std::vector<int> imhist(const Image& image, unsigned int n=256);
}