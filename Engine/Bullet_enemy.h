#pragma once
#include "Graphics.h"
#include "Colors.h"


class Bullet_enemy
{
public:
	Bullet_enemy(int xpos, int ypos, int targetx, int targety);
	int GetX();
	int GetY();
	void Update();
	void Draw(Graphics& gfx);

	bool colliding;
	static constexpr float damage = 5.00;

private:
	int x, y;
	float vx, vy;
	static constexpr int size = 4; //block shape
	const float speed = 5.0f;
	
	Color color;

};