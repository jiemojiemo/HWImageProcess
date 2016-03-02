#include "imadjust.h"
#include "HWImageProcess.h"
#include <cmath>
#include <assert.h>

double HW::gamma(double r, double g, double c )
{
	return c*std::pow(r, g);
}
Image HW::imadjust(const Image& f, double low_in, double high_in,
	double low_out, double high_out, double gammaScale)
{
	assert(low_in < high_in);
	double grayscale = 255.0;	// unsigned char is 255 only
	double slope =  (high_out - low_out)/ (high_in - low_in);
	double p = 0.0;
	double result = 0.0;
	Image g(f);
	FOR_EACH_COMPONENT(f.GetHeight(), f.GetWidth(), f.GetComponents())
	{
		p = f.At(i, j, k) / grayscale;

		if (LT(p,low_in))	//[p,low_in, high_in]
		{
			result = low_out;
		}
		else if (GE(p,low_in) && LE(p,high_in))	//[low_in,p,high_in]
		{
			result = (p - low_in) * slope + low_out;
			result = gamma(result, gammaScale);
		}
		else if (GT(p,high_in))	//[low_in, high_in, p]
		{
			result = high_out;
		}
		g.At(i, j, k) = unsigned char(round(result * grayscale));
	}
	return g;
}
Image HW::imadjust(const Image& f, const std::vector<double> low_high,
	double low_out, double high_out, double gammaScale /* = 1.0 */)
{
	assert(low_high.size() == 2);

	return HW::imadjust(f, low_high[0], low_high[1], low_out, high_out, gammaScale);
}