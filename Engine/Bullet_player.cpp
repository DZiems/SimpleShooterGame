#include "Bullet_player.h"
#include "Game.h"
#include <cmath>



Bullet_player::Bullet_player(int xpos, int ypos, int targetx, int targety) :
	color(125, 180, 180)
{
	
	colliding = false;
	x = xpos;
	y = ypos;

	//caluclate vx, vy, total = 20
	float to_targetx = targetx - xpos;
	float to_targety = targety - ypos;
	if (to_targetx == 0) 
	{
		if (to_targety >= 0)
			vy = speed;
		else
			vy = -speed;
		vx = 0;
	}
	else
	{
		float distance = sqrt((to_targetx * to_targetx) + (to_targety * to_targety));
		vx = speed * (to_targetx / distance);
		vy = speed * (to_targety / distance);
	}
	

}

int Bullet_player::GetX()
{
	return x;
}

int Bullet_player::GetY()
{
	return y;
}

void Bullet_player::Update()
{
	x += vx;
	y += vy;
	
	if (y + size >= Graphics::ScreenHeight - 1)
	{
		y = Graphics::ScreenHeight - size - 2;
		colliding = true;
	}
	if (y <= 0)
	{
		y = 1;
		colliding = true;
	}
	//clamp screen x
	if (x + size >= Graphics::ScreenWidth - 1)
	{
		x = Graphics::ScreenWidth - size - 2;
		colliding = true;
	}
	if (x <= 0)
	{
		x = 1;
		colliding = true;
	}
}


void Bullet_player::Draw(Graphics& gfx)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			gfx.PutPixel(x + i, y + j, color);
		}
	}
}
