#include "imhist.h"
#include "HWImageProcess.h"
#include <iostream>
std::vector<int> HW::imhist(const Image& image, unsigned int n /*= 256*/)
{
	std::vector<int> ans(n, 0);
	double grayscale = 256;
	int step = round(grayscale/n);
	int index = 0;
	FOR_EACH_COMPONENT_IMAGE(image)
	{
		index = image.At(i, j, k) / step;
		//if(index == 0)
		//{ 
		//	std::cout << (int)image.At(i, j, k) << std::endl;
		//	++ans[index];
		//}
		//else
		++ans[index];
	}
	return ans;
}