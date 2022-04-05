#include "Reticle.h"




Reticle::Reticle()
{
	x = Graphics::ScreenWidth/2;
	y = Graphics::ScreenHeight/2;
}

void Reticle::ToggleStyle()
{
	toggle_style = !toggle_style;
}

void Reticle::Draw( Graphics& gfx) const
{
	if (toggle_style)
	{
		//top left
		gfx.PutPixel(x - 5, y - 5, color);
		gfx.PutPixel(x - 5, y - 4, color);
		gfx.PutPixel(x - 5, y - 3, color);
		gfx.PutPixel(x - 4, y - 5, color);
		gfx.PutPixel(x - 3, y - 5, color);

		gfx.PutPixel(x - 5, y + 5, color);
		gfx.PutPixel(x - 5, y + 4, color);
		gfx.PutPixel(x - 5, y + 3, color);
		gfx.PutPixel(x - 4, y + 5, color);
		gfx.PutPixel(x - 3, y + 5, color);

		gfx.PutPixel(x + 5, y - 5, color);
		gfx.PutPixel(x + 5, y - 4, color);
		gfx.PutPixel(x + 5, y - 3, color);
		gfx.PutPixel(x + 4, y - 5, color);
		gfx.PutPixel(x + 3, y - 5, color);

		gfx.PutPixel(x + 5, y + 5, color);
		gfx.PutPixel(x + 4, y + 4, color);
		gfx.PutPixel(x + 3, y + 3, color);
		gfx.PutPixel(x + 5, y + 4, color);
		gfx.PutPixel(x + 5, y + 3, color);
		gfx.PutPixel(x + 4, y + 5, color);
		gfx.PutPixel(x + 3, y + 5, color);
	}
	else
	{
		gfx.PutPixel(x - 5, y - 5, color);
		gfx.PutPixel(x - 4, y - 4, color);
		gfx.PutPixel(x - 3, y - 3, color);

		gfx.PutPixel(x - 5, y + 5, color);
		gfx.PutPixel(x - 4, y + 4, color);
		gfx.PutPixel(x - 3, y + 3, color);

		gfx.PutPixel(x + 5, y - 5, color);
		gfx.PutPixel(x + 4, y - 4, color);
		gfx.PutPixel(x + 3, y - 3, color);

		gfx.PutPixel(x + 5, y + 5, color);
		gfx.PutPixel(x + 4, y + 4, color);
		gfx.PutPixel(x + 3, y + 3, color);
	}
}


int Reticle::GetX()
{
	return x;
}

int Reticle::GetY()
{
	return y;
}

void Reticle::Update(int xnew, int ynew)
{
	x = xnew;
	y = ynew;

	if (x + 5 >= Graphics::ScreenWidth - 1)
	{
		x = Graphics::ScreenWidth - 6;
	}
	if (x - 5 <= 0)
	{
		x = 6;
	}

	if (y + 5 >= Graphics::ScreenHeight - 1)
	{
		y = Graphics::ScreenHeight - 6;
	}
	if (y - 5 <= 0)
	{
		y = 6;
	}
}

