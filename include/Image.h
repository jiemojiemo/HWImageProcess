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
	Image(unsigned int w, unsigned int h, unsigned int n, const unsigned char* data);
	Image(const Image& image);
	Image& operator=(const Image& image);
	~Image();



	//getter and setter
	int GetWidth()const;
	int GetHeight()const;
	int GetComponents()const;
	unsigned char* GetData()const;

	const unsigned char& At(int row, int col, int nth)const;

	unsigned char&At(int row, int col, int nth);
};