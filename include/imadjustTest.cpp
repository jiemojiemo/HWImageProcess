#include "imadjust.h"
#include "ImageLWManager.h"

int main()
{
	ImageLWManager loadWrite;
	auto f = loadWrite.LoadImage("../Resource/Fig0303(a)(breast).jpg");
	auto g = HW::imadjust(f, 0, 1.0, 0, 1.0, 2);
	loadWrite.WritePNGImage(g, "imadjustTest.png");
	return 0;
}