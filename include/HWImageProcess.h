#pragma once

#define FOR_EACH_COMPONENT(I,J,N) \
	 for(int i = 0;i<(I);++i)	\
		for(int j=0;j<(J);++j)	\
			for(int k=0;k<(N);++k)
