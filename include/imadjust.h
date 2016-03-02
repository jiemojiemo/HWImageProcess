#pragma once
#include "Image.h"
#include <vector>
namespace HW
{
	/*
		s=cr^g
		c normal is 1
	*/	
	 double gamma(double r, double g,double c=1.0);
	 Image imadjust(const Image& f, double low_in, double high_in,
		double low_out, double high_out, double gammaScale=1.0);
	 Image imadjust(const Image& f, const std::vector<double> low_high,
		 double low_out, double high_out, double gammaScale = 1.0);
}
