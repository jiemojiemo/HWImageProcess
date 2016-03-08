#include "histeq.h"
#include "UnsignedImage.h"
#include "imhist.h"
#include "HWImageProcess.h"
#include <iostream>
#include <algorithm>
UnsignedImage HW::histeq(const UnsignedImage& image, unsigned int nlev /* = 256 */)
{
	// step 1: Normalized histogram
	auto hnorm = imhist(image);
	double pitSize = image.GetSize();
	auto maxGrayscale = hnorm.size();
	std::vector<double> p(maxGrayscale, 0);
	
	for (int i = 0; i < maxGrayscale; ++i)
	{
		p[i] = hnorm[i] / pitSize;
	}
	// step 2: cdf
	std::vector<double> cdf(nlev, 0);
	cdf[0] = p[0];
	for (int i = 1; i < maxGrayscale; ++i)
	{
		cdf[i] = cdf[i-1] + p[i];
	}
	UnsignedImage outImage(image);

	FOR_EACH_COMPONENT_IMAGE(outImage)
	{
		outImage.At(i, j, k) = round(cdf[image.At(i,j,k)] * (nlev-1));
	}

	return outImage;
}