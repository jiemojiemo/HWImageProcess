#include "ImageLWManager.h"
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"
UnsignedImage ImageLoader::LoadImage(const std::string& filePath, int req_comp /*= 0*/)
{
	int x, y, n;
	auto data = stbi_load(filePath.c_str(), &x, &y, &n, req_comp);

	if (req_comp != 0 && n > req_comp)
		n = req_comp;
	if (nullptr == data)
	{
		std::cerr << "Can't open the file.\n";
		exit(-1);
	}
	UnsignedImage image(x, y, n, data);

	return image;
}

int ImageWriter::WritePNGImage(const UnsignedImage& image, const std::string& outputPath)const
{
	return stbi_write_png(outputPath.c_str(),
		image.GetWidth(),
		image.GetHeight(),
		image.GetComponents(),
		&(image.GetData()[0]),
		0);
}