#include "Image.h"
#include <iostream>
Image::Image(int w, int h, int n):
	m_width(w), m_height(h), m_components(n)
{
}
Image::Image(const Image& image) :
	m_width(image.m_width),
	m_height(image.m_height),
	m_components(image.m_components)
{
}
Image::Image(Image&& image):
	m_width(image.m_width),
	m_height(image.m_height),
	m_components(image.m_components)
{
}


Image& Image::operator=(const Image& image)
{
	if (this == &image)
		return *this;

	m_width = image.m_width;
	m_height = image.m_height;
	m_components = image.m_components;
	return *this;
}

Image& Image::operator=(Image&& image)
{
	if (this == &image)
		return *this;

	m_width = image.m_width;
	m_height = image.m_height;
	m_components = image.m_components;

	return *this;
}

unsigned int Image::GetWidth()const{ return m_width; }

unsigned int  Image::GetHeight()const { return m_height; }

unsigned int  Image::GetComponents()const { return m_components; }



