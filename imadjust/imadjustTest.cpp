#include "imadjust.h"
#include "stretchlim.h"
#include "imhist.h"
#include "ImageLWManager.h"

int main()
{
	ImageLoader loader;
	auto f = loader.LoadImage("../Resource/Fig0310(a)(Moon Phobos).jpg");
	auto low_high(HW::strechlim(f));
	//auto hist(HW::imhist(f,255));
	auto g = HW::imadjust(f, low_high, 0,1);

	ImageWriter writer;
	writer.WritePNGImage(g, "imadjustTest.png");
	return 0;
}