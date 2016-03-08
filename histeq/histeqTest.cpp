#include "histeq.h"
#include "ImageLWManager.h"
int main()
{
	ImageLoader loader;
	auto f = loader.LoadImage("../Resource/Fig0308(a)(pollen).jpg");
	auto g = HW::histeq(f);

	ImageWriter writer;
	writer.WritePNGImage(g, "histTest.png");
}