#pragma once
#include <assert.h>
#include <cstring>

class Image
{
protected:
	unsigned int m_width;
	unsigned int m_height;
	unsigned int m_components;
public:
	Image(int w,int h,int n);
	Image(const Image& image);
	Image(Image&& image);
	Image& operator=(const Image& image);
	Image& operator=(Image&& image);
	virtual ~Image()=default;

	//getter and setter
	unsigned int GetWidth()const;
	unsigned int GetHeight()const;
	unsigned int GetComponents()const;
};



