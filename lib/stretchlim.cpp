#include "stretchlim.h"
#include "imhist.h"
#include "HWImageProcess.h"
#include <numeric>
std::vector<double> HW::strechlim(const UnsignedImage& image)
{
	double grayscale = 255.0;

	auto hist = imhist(image);
	auto toltalSize = std::accumulate(hist.begin(), hist.end(), 0);
	double tol_low = 0.01;
	double tol_high = 0.99;
	std::vector<double> lowHigh(2);
	// find the first position which \sum_{i=0}^p >= tol_low
	for (int i = 0; i < hist.size(); ++i)
	{
		auto sum = std::accumulate(hist.begin(), hist.begin() + i, 0.0);
		if (GE(sum / toltalSize, tol_low))	// > tol_low
		{
			lowHigh[0] = i / grayscale;
			break;
		}
	}
	// find the first position which \sum_{i=0}^p >= tol_high
	for (int i = 0; i < hist.size(); ++i)
	{
		auto sum = std::accumulate(hist.begin(), hist.begin() + i, 0.0);
		if (GE(sum / toltalSize, tol_high))	// > tol_high
		{
			lowHigh[1] = i / grayscale;
			break;
		}
	}
	return lowHigh;
}