#include "imadjust.h"
#include "HWImageProcess.h"
#include <cmath>

double HW::gamma(double r, double g, double c )
{
	return c*std::pow(r, g);
}
Image HW::imadjust(const Image& f, double low_in, double high_in,
	double low_out, double high_out, double gammaScale)
{
	double grayscale = 255.0;	// unsigned char is 255 only
	double step = (high_in - low_in) / (high_out - low_out);
	Image g(f);
	FOR_EACH_COMPONENT(f.GetHeight(), f.GetWidth(), f.GetComponents())
	{
		double p = f.At(i, j, k) / grayscale;
		double step = (high_out - low_out) / (high_in - low_in);
		double result = 0.0;

		if (p < low_in)	//[p,low_in, high_in]
		{
			result = low_out;
		}
		else if (p >= low_in && p <= high_in)	//[low_in,p,high_in]
		{
			result = gamma(p, gammaScale);
		}
		else if (p > high_in)	//[low_in, high_in, p]
		{
			p = high_out;
		}
		g.At(i, j, k) = unsigned char(result * grayscale * step);
	}
	return g;
}
