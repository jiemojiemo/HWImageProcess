#include "imadjust.h"
#include "stretchlim.h"
#include "imhist.h"
#include "ImageLWManager.h"

int main()
{
	ImageLWManager loadWrite;
	auto f = loadWrite.LoadImage("../Resource/Fig0303(a)(breast).jpg");
	auto low_high(HW::strechlim(f));
	//auto hist(HW::imhist(f,255));
	auto g = HW::imadjust(f, low_high, 1,0);
	loadWrite.WritePNGImage(g, "imadjustTest.png");
	return 0;
}