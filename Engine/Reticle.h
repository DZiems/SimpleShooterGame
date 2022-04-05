#pragma once
#include "Colors.h"
#include "Graphics.h"

//follow the cursor around the window
//10 pixels size, based around the center
class Reticle
{

public:
	Reticle();
	void ToggleStyle();
	void Draw( Graphics& gfx ) const;

	int GetX();
	int GetY();
	//reticle position will follow mouse
	void Update(int xnew, int ynew);
private:
	bool toggle_style;
	Color color = Colors::White;
	int x;
	int y;
};