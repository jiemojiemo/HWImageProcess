#include "UnsignedImage.h"

UnsignedImage::UnsignedImage(int w, int h, int n, const void* data) :
	Image(w, h, n)
{
	m_data = new unsigned char[m_width*m_height*m_components];
	memcpy(m_data, data, sizeof(unsigned char) * m_width*m_height*m_components);
}

UnsignedImage::UnsignedImage(const UnsignedImage& image) :
	Image(image.m_width, image.m_height, image.m_components)
{
	m_data = new unsigned char[m_width*m_height*m_components];
	memcpy(m_data, image.m_data, sizeof(unsigned char) * m_width*m_height*m_components);
}

UnsignedImage::UnsignedImage(UnsignedImage&& image) :
	Image(image.m_width, image.m_height, image.m_components),
	m_data(image.m_data)
{
	image.m_data = nullptr;
}

UnsignedImage& UnsignedImage::operator=(const UnsignedImage& image)
{
	if (this == &image)
		return *this;
	this->Image::operator =(image);
	delete[] m_data;
	unsigned int size = m_width*m_height*m_components;
	m_data = new unsigned char[size];
	memcpy(m_data, image.m_data, sizeof(unsigned char)*size);
	return *this;
}

UnsignedImage& UnsignedImage::operator=(UnsignedImage&& image)
{
	if (this == &image)
		return *this;

	delete[] m_data;
	this->Image::operator =(image);
	m_data = image.m_data;
	image.m_data = nullptr;
	return *this;
}
UnsignedImage::~UnsignedImage()
{
	if (nullptr != m_data)
		delete[] m_data;
}

unsigned char* UnsignedImage::GetData()const
{
	return m_data;
}

const unsigned char & UnsignedImage::At(int row, int col, int nth)const
{
	assert(row <= m_height && col <= m_width && nth <= m_components);
	return m_data[row*m_width*m_components + col*m_components + nth];
}
unsigned char& UnsignedImage::At(int row, int col, int nth)
{
	assert(row <= m_height && col <= m_width && nth <= m_components);
	return m_data[row*m_width*m_components + col*m_components + nth];
}