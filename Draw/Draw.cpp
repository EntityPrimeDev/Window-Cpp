#include "Draw.h"

void Draw::K2_Box(HDC hdc)
{
	Gdiplus::Graphics gf(hdc);
	Gdiplus::Pen pen(Gdiplus::Color(255, 255, 0, 255));
	Gdiplus::SolidBrush  brush(Gdiplus::Color(255, 0, 0, 255));

	gf.DrawRectangle(&pen, x_draw, y_draw, 50, 50);
}
