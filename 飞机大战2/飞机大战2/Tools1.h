#ifndef __TOOLS1_H__
#define __TOOLS1_H__

#include<easyx.h>
#pragma comment(lib,"MSIMG32.LIB")

class Tools1
{
public:
	static void putimage_alpha(int x, int y, IMAGE* img)
	{
		int w = img->getwidth();
		int h = img->getheight();
		AlphaBlend(GetImageHDC(NULL), x, y, w, h, GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER,0,255,AC_SRC_ALPHA });

	}
};


#endif  // !__TOOLS1_H__


