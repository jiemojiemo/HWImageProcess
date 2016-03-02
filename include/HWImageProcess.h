#pragma once
#include <cfloat>
#define FOR_EACH_COMPONENT_IMAGE(IMAGE)	\
	for(int i = 0; i<(IMAGE.GetHeight()); ++i)	\
		for(int j=0;j<(IMAGE.GetWidth());++j)	\
			for(int k=0;k<(IMAGE.GetComponents());++k)
#define FOR_EACH_COMPONENT(I,J,N) \
	 for(int i = 0;i<(I);++i)	\
		for(int j=0;j<(J);++j)	\
			for(int k=0;k<(N);++k)


const float EPSINON = FLT_MIN;
static bool EQ(double x, double y) { if (fabs(x - y) < EPSINON) return true; return false; }
static bool NE(double x, double y) { if (!EQ(x, y)) return true; return false; }
static bool LT(double x, double y) { if ((y - x) > EPSINON) return true; return false; }
static bool LE(double x, double y) { if (LT(x, y) || EQ(x, y)) return true; return false; }
static bool GT(double x, double y) { if (!LE(x, y)) return true; return false; }
static bool GE(double x, double y) { if (!LT(x, y)) return true; return false; }