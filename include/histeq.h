#pragma once
#include <vector>
class UnsignedImage;
namespace HW
{
	//UnsignedImage histeq(const std::vector<unsigned char> vec, unsigned int nlev = 256 );
	UnsignedImage histeq(const UnsignedImage& image, unsigned int nlev = 256);
}