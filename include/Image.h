#pragma once
#include <assert.h>
#include <cstring>
class Image
{
private:
	int m_width;
	int m_height;
	int m_components;
	unsigned char* m_data;
public:
	Image(unsigned int w, unsigned int h, unsigned int n, const unsigned char* data):
		m_width(w), m_height(h), m_components(n)
	{
		m_data = new unsigned char[w*h*n];
		memcpy(m_data, data, w*h*n);
	}
	~Image()
	{
		if (nullptr != m_data)
			delete[] m_data;
	}

	//getter and setter
	int GetWidth()const { return m_width; }
	int GetHeight()const { return m_height; }
	int GetComponents()const { return m_components; }

	const int At(int row, int col, int nth)const
	{
		assert(row <= m_height && col <= m_width && n <= m_components);
		return m_data[row*m_width*m_components + col*m_components + n];
	}
	int&At(int row, int col, int nth)
	{
		assert(row <= m_height && col <= m_width && n <= m_components);
		return m_data[row*m_width*m_components + col*m_components + n];
	}
};