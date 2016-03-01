#include "Image.h"
#include <iostream>
Image::Image(unsigned int w, unsigned int h, unsigned int n,
	const unsigned char* data):
	m_width(w), m_height(h), m_components(n)
{
	m_data = new unsigned char[w*h*n];
	memcpy(m_data, data, w*h*n);
}
Image::Image(const Image& image) :
	m_width(image.m_width),
	m_height(image.m_height),
	m_components(image.m_components)
{
	int wholeSize = m_width*m_height*m_components;
	m_data = new unsigned char[wholeSize];
	memcpy(m_data, image.GetData(), wholeSize);
}
Image::Image(Image&& image):
	m_width(image.m_width),
	m_height(image.m_height),
	m_components(image.m_components),
	m_data(image.m_data)
{
	image.m_data = nullptr;
}
Image& Image::operator=(const Image& image)
{
	if (this == &image)
		return *this;

	delete[] m_data;
	m_width = image.m_width;
	m_height = image.m_height;
	m_components = image.m_components;
	unsigned int size = m_width*m_height*m_components;
	m_data = new unsigned char[size];
	memcpy(m_data, image.m_data, size);
	return *this;
}
Image& Image::operator=(Image&& image)
{
	if (this == &image)
		return *this;

	delete[] m_data;
	m_width = image.m_width;
	m_height = image.m_height;
	m_components = image.m_components;
	m_data = image.m_data;

	return *this;
}
Image::~Image()
{
	if (nullptr != m_data)
		delete[] m_data;
}

int Image::GetWidth()const{ return m_width; }
int Image::GetHeight()const { return m_height; }
int Image::GetComponents()const { return m_components; }
unsigned char* Image::GetData()const { return m_data; }

const unsigned char& Image::At(int row, int col, int nth)const
{
	assert(row <= m_height && col <= m_width && nth <= m_components);
	return m_data[row*m_width*m_components + col*m_components + nth];
}
unsigned char& Image::At(int row, int col, int nth)
{
	assert(row <= m_height && col <= m_width && nth <= m_components);
	return m_data[row*m_width*m_components + col*m_components + nth];
}