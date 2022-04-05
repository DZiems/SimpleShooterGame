#include "Player.h"

Player::Player()
{
	hp_current = hp_total;
	x = spawnX;
	y = spawnY;
	mag_current = mag_total;
	vx = 0;
	vy = 0;

	color_body_current = color_body_original;
	color_head_current = color_head_original;


	for (int i = 0; i < mag_total; i++)
	{
		bullet[i] = nullptr;
	}
}


int Player::GetX()
{
	return x;
}

int Player::GetY()
{
	return y;
}

float Player::GetCurrentHP()
{
	return hp_current;
}



void Player::Update_mvmnt(const Keyboard& kbd)
{

	if (kbd.KeyIsPressed('W'))
	{
		y -= (speed/2);
		vy = -speed;
	}
	if (kbd.KeyIsPressed('A'))
	{
		x -= (speed / 2);
		vx = -speed;
	}
	if (kbd.KeyIsPressed('S'))
	{
		y += (speed / 2);
		vy = speed;
	}
	if (kbd.KeyIsPressed('D'))
	{
		x += (speed / 2);
		vx = speed;
	}

	//movement
	x += vx;
	y += vy;
	

//clamp screen y
if (y + size >= Graphics::ScreenHeight - 1)
{
	y = Graphics::ScreenHeight - size - 2;
}
if (y <= 0)
{
	y = 1;
}
//clamp screen x
if (x + size >= Graphics::ScreenWidth - 1)
{
	x = Graphics::ScreenWidth - size - 2;
}
if (x <= 0)
{
	x = 1;
}

//friction
if (vx > 0)
vx -= frictionFactor;
if (vx < 0)
	vx += frictionFactor;
if (vy > 0)
vy -= frictionFactor;
if (vy < 0)
	vy += frictionFactor;
}

void Player::Update_healthNcolor(Bullet_enemy* bullet[])
{
	//if hit by bullet
	for (int i = 0; i < Enemy::mag_total; i++)
	{
		if (bullet[i] != nullptr)
		{
			if ((bullet[i]->GetX() >= x) &&
				(bullet[i]->GetX() <= x + size) &&
				(bullet[i]->GetY() >= y) &&
				(bullet[i]->GetY() <= y + size))
			{
				if (hp_current > 0)
				{
					hp_current -= Bullet_enemy::damage;
				}

				float damage_effect = (1 - ((1 - (hp_current / hp_total)) / 1.5));
				color_body_current.SetR(color_body_original.GetR() * damage_effect);
				color_body_current.SetG(color_body_original.GetG() * damage_effect);
				color_body_current.SetB(color_body_original.GetB() * damage_effect);

				color_head_current.SetR(color_head_original.GetR() * damage_effect);
				color_head_current.SetG(color_head_original.GetG() * damage_effect);
				color_head_current.SetB(color_head_original.GetB() * damage_effect);

				bullet[i]->colliding = true;
			}
		}
	}
}

void Player::Recover()
{
	hp_current = hp_total;
}

void Player::ResetSpawnPt()
{
	x = spawnX;
	y = spawnY;
}



void Player::Fire(Reticle ret, const Mouse& mouse, bool& leftclick_buffer)
{
	if (mouse.LeftIsPressed())
	{
		if (!leftclick_buffer)
		{
			for (int i = 0; i < mag_total; i++)
			{
				if (bullet[i] == nullptr)
				{
					bullet[i] = new Bullet_player((x + (size / 2)), (y + (size / 2)), ret.GetX(), ret.GetY());
					leftclick_buffer = true;
					return;
				}
			}
		}
	}
	else
	{
		leftclick_buffer = false;
	}
}

void Player::Update_Bullets(Bullet_player* bullet[])
{
	for (int i = 0; i < mag_total; i++)
	{
		if (bullet[i] != nullptr)
		{
			bullet[i]->Update();
			if (bullet[i]->colliding)
			{
				delete bullet[i];
				bullet[i] = nullptr;
			}
		}
		
	}
}



void Player::Draw(Graphics& gfx, Reticle& ret)
{
	//(temporary) assuming constant size of 60 including head
	int half2 = size / 2;
	int half1 = (size / 2) - 1;

	//body of player, a circle of 40 size
	{

	//left side	

							gfx.PutPixel(x + 16, y + 16, color_body_current);
						gfx.PutPixel(x + 15, y + 16, color_body_current);
						gfx.PutPixel(x + 15, y + 17, color_body_current);
					gfx.PutPixel(x + 14, y + 17, color_body_current);
					gfx.PutPixel(x + 14, y + 18, color_body_current);
					gfx.PutPixel(x + 14, y + 19, color_body_current);
				gfx.PutPixel(x + 13, y + 19, color_body_current);
				gfx.PutPixel(x + 13, y + 20, color_body_current);
			gfx.PutPixel(x + 12, y + 20, color_body_current);
			gfx.PutPixel(x + 12, y + 21, color_body_current);
			gfx.PutPixel(x + 12, y + 22, color_body_current);
		gfx.PutPixel(x + 11, y + 22, color_body_current);
		gfx.PutPixel(x + 11, y + 23, color_body_current);
		gfx.PutPixel(x + 11, y + 24, color_body_current);
		gfx.PutPixel(x + 11, y + 25, color_body_current);
		gfx.PutPixel(x + 11, y + 26, color_body_current);
	gfx.PutPixel(x + 10, y + 26, color_body_current);
	gfx.PutPixel(x + 10, y + 27, color_body_current);
	gfx.PutPixel(x + 10, y + 28, color_body_current);
	gfx.PutPixel(x + 10, y + half1, color_body_current);
	
	gfx.PutPixel(x + 10, y + half2, color_body_current);
	gfx.PutPixel(x + 10, y + 31, color_body_current);
	gfx.PutPixel(x + 10, y + 32, color_body_current);
	gfx.PutPixel(x + 10, y + 33, color_body_current);
		gfx.PutPixel(x + 11, y + 33, color_body_current);
		gfx.PutPixel(x + 11, y + 34, color_body_current);
		gfx.PutPixel(x + 11, y + 35, color_body_current);
		gfx.PutPixel(x + 11, y + 36, color_body_current);
		gfx.PutPixel(x + 11, y + 37, color_body_current);
			gfx.PutPixel(x + 12, y + 37, color_body_current);
			gfx.PutPixel(x + 12, y + 38, color_body_current);
			gfx.PutPixel(x + 12, y + 39, color_body_current); 
				gfx.PutPixel(x + 13, y + 39, color_body_current);
				gfx.PutPixel(x + 13, y + 40, color_body_current);
					gfx.PutPixel(x + 14, y + 40, color_body_current);
					gfx.PutPixel(x + 14, y + 41, color_body_current);
					gfx.PutPixel(x + 14, y + 42, color_body_current);
						gfx.PutPixel(x + 15, y + 42, color_body_current);
						gfx.PutPixel(x + 15, y + 43, color_body_current);
							gfx.PutPixel(x + 16, y + 43, color_body_current);

	//right side

	gfx.PutPixel(x + 43, y + 16, color_body_current);
		gfx.PutPixel(x + 44, y + 16, color_body_current);
		gfx.PutPixel(x + 44, y + 17, color_body_current);
			gfx.PutPixel(x + 45, y + 17, color_body_current);
			gfx.PutPixel(x + 45, y + 18, color_body_current);
			gfx.PutPixel(x + 45, y + 19, color_body_current);
				gfx.PutPixel(x + 46, y + 19, color_body_current);
				gfx.PutPixel(x + 46, y + 20, color_body_current);
					gfx.PutPixel(x + 47, y + 20, color_body_current);
					gfx.PutPixel(x + 47, y + 21, color_body_current);
					gfx.PutPixel(x + 47, y + 22, color_body_current);
						gfx.PutPixel(x + 48, y + 22, color_body_current);
						gfx.PutPixel(x + 48, y + 23, color_body_current);
						gfx.PutPixel(x + 48, y + 24, color_body_current);
						gfx.PutPixel(x + 48, y + 25, color_body_current);
						gfx.PutPixel(x + 48, y + 26, color_body_current);
							gfx.PutPixel(x + 49, y + 26, color_body_current);
							gfx.PutPixel(x + 49, y + 27, color_body_current);
							gfx.PutPixel(x + 49, y + 28, color_body_current);
							gfx.PutPixel(x + 49, y + half1, color_body_current);

							gfx.PutPixel(x + 49, y + half2, color_body_current);
							gfx.PutPixel(x + 49, y + 31, color_body_current);
							gfx.PutPixel(x + 49, y + 32, color_body_current);
							gfx.PutPixel(x + 49, y + 33, color_body_current);
						gfx.PutPixel(x + 48, y + 33, color_body_current);
						gfx.PutPixel(x + 48, y + 34, color_body_current);
						gfx.PutPixel(x + 48, y + 35, color_body_current);
						gfx.PutPixel(x + 48, y + 36, color_body_current);
						gfx.PutPixel(x + 48, y + 37, color_body_current);
					gfx.PutPixel(x + 47, y + 37, color_body_current);
					gfx.PutPixel(x + 47, y + 38, color_body_current);
					gfx.PutPixel(x + 47, y + 39, color_body_current);
				gfx.PutPixel(x + 46, y + 39, color_body_current);
				gfx.PutPixel(x + 46, y + 40, color_body_current);
			gfx.PutPixel(x + 45, y + 40, color_body_current);
			gfx.PutPixel(x + 45, y + 41, color_body_current);
			gfx.PutPixel(x + 45, y + 42, color_body_current);
		gfx.PutPixel(x + 44, y + 42, color_body_current);
		gfx.PutPixel(x + 44, y + 43, color_body_current);
	gfx.PutPixel(x + 43, y + 43, color_body_current);


	//top side
	gfx.PutPixel(x + 16, y + 44, color_body_current);
	gfx.PutPixel(x + 17, y + 44, color_body_current);
		gfx.PutPixel(x + 17, y + 45, color_body_current);
		gfx.PutPixel(x + 18, y + 45, color_body_current);
		gfx.PutPixel(x + 19, y + 45, color_body_current);
			gfx.PutPixel(x + 19, y + 46, color_body_current);
			gfx.PutPixel(x + 20, y + 46, color_body_current);
				gfx.PutPixel(x + 20, y + 47, color_body_current);
				gfx.PutPixel(x + 21, y + 47, color_body_current);
				gfx.PutPixel(x + 22, y + 47, color_body_current);
					gfx.PutPixel(x + 22, y + 48, color_body_current);
					gfx.PutPixel(x + 23, y + 48, color_body_current);
					gfx.PutPixel(x + 24, y + 48, color_body_current);
					gfx.PutPixel(x + 25, y + 48, color_body_current);
					gfx.PutPixel(x + 26, y + 48, color_body_current);
						gfx.PutPixel(x + 26, y + 49, color_body_current);
						gfx.PutPixel(x + 27, y + 49, color_body_current);
						gfx.PutPixel(x + 28, y + 49, color_body_current);
						gfx.PutPixel(x + half1, y + 49, color_body_current);
												 
						gfx.PutPixel(x + half2, y + 49, color_body_current);
						gfx.PutPixel(x + 31, y + 49, color_body_current);
						gfx.PutPixel(x + 32, y + 49, color_body_current);
						gfx.PutPixel(x + 33, y + 49, color_body_current);
					gfx.PutPixel(x + 33, y + 48, color_body_current);
					gfx.PutPixel(x + 34, y + 48, color_body_current);
					gfx.PutPixel(x + 35, y + 48, color_body_current);
					gfx.PutPixel(x + 36, y + 48, color_body_current);
					gfx.PutPixel(x + 37, y + 48, color_body_current);
				gfx.PutPixel(x + 37, y + 47, color_body_current);
				gfx.PutPixel(x + 38, y + 47, color_body_current);
				gfx.PutPixel(x + 39, y + 47, color_body_current);
			gfx.PutPixel(x + 39, y + 46, color_body_current);
			gfx.PutPixel(x + 40, y + 46, color_body_current);
		gfx.PutPixel(x + 40, y + 45, color_body_current);
		gfx.PutPixel(x + 41, y + 45, color_body_current);
		gfx.PutPixel(x + 42, y + 45, color_body_current);
	gfx.PutPixel(x + 42, y + 44, color_body_current);
	gfx.PutPixel(x + 43, y + 44, color_body_current);


	//bottom side

						gfx.PutPixel(x + 16, y + 15, color_body_current);
						gfx.PutPixel(x + 17, y + 15, color_body_current);
					gfx.PutPixel(x + 17, y + 14, color_body_current);
					gfx.PutPixel(x + 18, y + 14, color_body_current);
					gfx.PutPixel(x + 19, y + 14, color_body_current);
				gfx.PutPixel(x + 19, y + 13, color_body_current);
				gfx.PutPixel(x + 20, y + 13, color_body_current);
			gfx.PutPixel(x + 20, y + 12, color_body_current);
			gfx.PutPixel(x + 21, y + 12, color_body_current);
			gfx.PutPixel(x + 22, y + 12, color_body_current);
		gfx.PutPixel(x + 22, y + 11, color_body_current);
		gfx.PutPixel(x + 23, y + 11, color_body_current);
		gfx.PutPixel(x + 24, y + 11, color_body_current);
		gfx.PutPixel(x + 25, y + 11, color_body_current);
		gfx.PutPixel(x + 26, y + 11, color_body_current);
	gfx.PutPixel(x + 26, y + 10, color_body_current);
	gfx.PutPixel(x + 27, y + 10, color_body_current);
	gfx.PutPixel(x + 28, y + 10, color_body_current);
	gfx.PutPixel(x + half1, y + 10, color_body_current);
	
	gfx.PutPixel(x + half2, y + 10, color_body_current);
	gfx.PutPixel(x + 31, y + 10, color_body_current);
	gfx.PutPixel(x + 32, y + 10, color_body_current);
	gfx.PutPixel(x + 33, y + 10, color_body_current);
		gfx.PutPixel(x + 33, y + 11, color_body_current);
		gfx.PutPixel(x + 34, y + 11, color_body_current);
		gfx.PutPixel(x + 35, y + 11, color_body_current);
		gfx.PutPixel(x + 36, y + 11, color_body_current);
		gfx.PutPixel(x + 37, y + 11, color_body_current);
			gfx.PutPixel(x + 37, y + 12, color_body_current);
			gfx.PutPixel(x + 38, y + 12, color_body_current);
			gfx.PutPixel(x + 39, y + 12, color_body_current);
				gfx.PutPixel(x + 39, y + 13, color_body_current);
				gfx.PutPixel(x + 40, y + 13, color_body_current);
					gfx.PutPixel(x + 40, y + 14, color_body_current);
					gfx.PutPixel(x + 41, y + 14, color_body_current);
					gfx.PutPixel(x + 42, y + 14, color_body_current);
						gfx.PutPixel(x + 42, y + 15, color_body_current);
						gfx.PutPixel(x + 43, y + 15, color_body_current);

	}


	//head (points approximately to reticle)
		//update the direction the player faces
	float to_retx = (x + (size/2)) - ret.GetX();
	float to_rety = (y + (size/2)) - ret.GetY();

	//special case
	if (to_retx == 0)
	{
		if (to_rety >= 0)
		{
			//points up
			int i = 0;
			while (i < 10)
			{
				gfx.PutPixel(x + half1, y + i, color_head_current);
				gfx.PutPixel(x + half2, y + i, color_head_current);
				i++;
			}
		}
		else
		{
			//points down
			int j = size - 10;
			while (j < size)
			{
				gfx.PutPixel(x + half1, y + j, color_head_current);
				gfx.PutPixel(x + half2, y + j, color_head_current);
				j++;
			}
		}
		return;
	}

	float facing = to_rety / to_retx;

	//quadrants
	//top left corner (x+ y+)
	if (to_retx > 0 && to_rety > 0)
	{
		if (facing > tan67_5) //face up
		{
			int i = 0;
			while (i < 10)
			{
				gfx.PutPixel(x + half1, y + i, color_head_current);
				gfx.PutPixel(x + half2, y + i, color_head_current);
				i++;
			}
		}
		else if (facing < (1/tan67_5)) //face left
		{
			int i = 0;
			while (i < 10)
			{
				gfx.PutPixel(x + i, y + half1, color_head_current);
				gfx.PutPixel(x + i, y + half2, color_head_current);
				i++;
			}
		}
		else //face up-left
		{
			int i = 12;
			int j = 12;
			while (i > 4 && j > 4)
			{
				gfx.PutPixel((x + i + 1), y + j, color_head_current);
				gfx.PutPixel(x + i, y + j, color_head_current);
				gfx.PutPixel(x + i, (y + j + 1), color_head_current);
				i--;
				j--;
			}
		}
	}

	//bottom right corner
	if (to_retx < 0 && to_rety < 0)
	{
		if (facing > tan67_5) //face down
		{
			int j = size - 10;
			while (j < size)
			{
				gfx.PutPixel(x + half1, y + j, color_head_current);
				gfx.PutPixel(x + half2, y + j, color_head_current);
				j++;
			}
		}
		else if (facing < (1 / tan67_5)) //face right
		{
			int j = size - 10;
			while (j < size)
			{
				gfx.PutPixel(x + j, y + half1, color_head_current);
				gfx.PutPixel(x + j, y + half2, color_head_current);
				j++;
			}
		}
		else //face down-right
		{
			int i = (size - 1) - 12;
			int j = (size - 1) - 12;
			while (i < (size - 1) - 4 && j < (size - 1) - 4)
			{
				gfx.PutPixel(x + i - 1, y + j, color_head_current);
				gfx.PutPixel(x + i, y + j, color_head_current);
				gfx.PutPixel(x + i, y + j - 1, color_head_current);
				i++;
				j++;
			}
		}
	}

	//bottom left corner
	if (to_retx > 0 && to_rety < 0)
	{
		if (facing < -tan67_5) //face down
		{
			int j = size - 10;
			while (j < size)
			{
				gfx.PutPixel(x + half1, y + j, color_head_current);
				gfx.PutPixel(x + half2, y + j, color_head_current);
				j++;
			}
		}
		else if (facing > -(1 / tan67_5)) //face left
		{
			int i = 0;
			while (i < 10)
			{
				gfx.PutPixel(x + i, y + half1, color_head_current);
				gfx.PutPixel(x + i, y + half2, color_head_current);
				i++;
			}
		}
		else //face down-left
		{
			int i = 12;
			int j = (size - 1) - 12;
			while (i > 4 && j < (size - 1) - 4)
			{
				gfx.PutPixel((x + i + 1), y + j, color_head_current);
				gfx.PutPixel(x + i, y + j, color_head_current);
				gfx.PutPixel(x + i, y + j - 1, color_head_current);
				i--;
				j++;
			}
		}
	}

	//top right corner
	if (to_retx < 0 && to_rety > 0)
	{
		if (facing < -tan67_5) //face up
		{
			int i = 0;
			while (i < 10)
			{
				gfx.PutPixel(x + half1, y + i, color_head_current);
				gfx.PutPixel(x + half2, y + i, color_head_current);
				i++;
			}
		}
		else if (facing > -(1 / tan67_5)) //face right
		{
			int j = size - 10;
			while (j < size)
			{
				gfx.PutPixel(x + j, y + half1, color_head_current);
				gfx.PutPixel(x + j, y + half2, color_head_current);
				j++;
			}
		}
		else //face up-right
		{
			int i = (size - 1) - 12;
			int j = 12;
			while (i < (size - 1) - 4 && j > 4)
			{
				gfx.PutPixel(x + i - 1, y + j, color_head_current);
				gfx.PutPixel(x + i, y + j, color_head_current);
				gfx.PutPixel(x + i, (y + j + 1), color_head_current);
				i++;
				j--;
			}
		}
	}

}

void Player::DrawHUD(Graphics& gfx)
{
	//draw hpbar
		Color frame_color(150, 150, 150);
		Color bar_color(200, 0, 0);

		//go from top right corner:
		int posframeX = Graphics::ScreenWidth - 6;
		int posframeY = 5;
		int posbarX = posframeX - 5;
		int posbarY = posframeY + 5;
		int lengthframeX = 210;
		int lengthframeY = 60;
		float lengthbarX = lengthframeX - 10;	//200
		int lengthbarY = lengthframeY - 10; //50


		//draw frame
		for (int i = 0; i < lengthframeX; i++)
		{
			gfx.PutPixel(posframeX - i, posframeY, frame_color);
			gfx.PutPixel(posframeX - i, (posframeY + lengthframeY), frame_color);
		}
		for (int j = 0; j < lengthframeY; j++)
		{
			gfx.PutPixel(posframeX, posframeY + j, frame_color);
			gfx.PutPixel((posframeX - lengthframeX), posframeY + j, frame_color);
		}


		//draw hp bar
		for (int i = 0; i < (lengthbarX * (hp_current / hp_total)); i++)
		{
			for (int j = 0; j < lengthbarY; j++)
			{
				gfx.PutPixel((posbarX - i), (posbarY + j), bar_color);
			}
		}

	
	//draw ammo
	Color ammo_color(125, 180, 180);
	int posammoX = posframeX - lengthframeX + 5;
	int posammoY = posframeY + lengthframeY + 5;
	int lengthammoX = 5;
	int lengthammoY = 10;

	for (int i = 0; i < mag_total; i++)
	{
		if (bullet[i] == nullptr)
		{
			for (int j = 0; j < lengthammoX; j++)
			{
				for (int k = 0; k < lengthammoY; k++)
				{
					gfx.PutPixel(posammoX + j, posammoY + k, ammo_color);
				}
			}
		}
		if (posammoX + (lengthammoX * 2) <= (Graphics::ScreenWidth - 1))
		{
			posammoX += (lengthammoX * 2);
		}
	}
}
