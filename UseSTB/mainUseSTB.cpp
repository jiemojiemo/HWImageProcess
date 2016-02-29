#include "common/scopeguard.h"
#include <iostream>
#include <string>
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

void ImageLoadTest();
void ImageWriteTest();
using std::cout;
using std::endl;
int main()
{
	ImageWriteTest();
	return 0;
}
void ImageLoadTest()
{
	int x, y, n;
	const char* fileName = "../Resource/clockA-t.jpg";
	auto data = stbi_load(fileName, &x, &y, &n, 0);
	if (nullptr == data)
	{
		cout << "Can't open the file.\n";
		return;
	}
	ON_SCOPE_EXIT([&data]() {stbi_image_free(data); });
	cout << "width=" << x << endl;
	cout << "height=" << y << endl;
	for (int i = 256; i < 260; ++i)
		cout << int(data[i]) << endl;
}
void ImageWriteTest()
{
	//First open a image
	int x, y, n;
	const char* fileName = "../Resource/low2.jpg";
	auto data = stbi_load(fileName, &x, &y, &n, 0);
	cout << x << " " << y << " " << n << endl;
	if (nullptr == data)
	{
		cout << "Can't open the file.\n";
		return;
	}
	
	//Do something
	for (int i = 0; i < x*y*n; i+=n)
	{
		for (int j = 0; j < n; ++j)
		{
			data[i + j] = 255 - data[i + j];
		}
	}
	//Save the processed image
	const char* outFileName = "XclockA-t.png";
	int ret = stbi_write_png(outFileName,x,y,n,data,0);
	cout << ret << endl;
}