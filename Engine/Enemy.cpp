#include "Enemy.h"
#include <cstdlib>




Enemy::Enemy()
{
	x = rand() % Graphics::ScreenWidth - size - 1;
	y = rand() % Graphics::ScreenHeight - size - 1;

	vx = -speed; 
	vy = -speed;


	while (	x >= Player::spawnX - (Player::size) &&
			x <= Player::spawnX + Player::size + (Player::size) &&
			y >= Player::spawnY - (Player::size) &&
			y <= Player::spawnY + Player::size + (Player::size))
	{
		x = rand() % Graphics::ScreenWidth - size - 1;
		y = rand() % Graphics::ScreenHeight - size - 1;
	}

	if (y <= 0)
	{
		y = 1;
		vy = -vy;
	}
	if (x <= 0)
	{
		x = 1;
		vx = -vx;
	}
	if (x >= Graphics::ScreenWidth - size - 1)
	{
		x = Graphics::ScreenWidth - size - 2;
	}
	if (y >= Graphics::ScreenHeight - size - 1)
	{
		y = Graphics::ScreenHeight - size - 2;
	}

	hp_current = hp_total;

	color_body_current = color_body_original;
	color_head_current = color_head_original;
}

void Enemy::Update_mvmnt()
{
	

	//update movement
	x += vx;
	y += vy;
	
	//clamp screen y
	if (y + size >= Graphics::ScreenHeight - 1)
	{
		y = Graphics::ScreenHeight - size - 2;
		vy = -vy;
	}
	if (y <= 0)
	{
		y = 1;
		vy = -vy;
	}
	//clamp screen x
	if (x + size >= Graphics::ScreenWidth - 1)
	{
		x = Graphics::ScreenWidth - size - 2;
		vx = -vx;
	}
	if (x <= 0)
	{
		x = 1;
		vx = -vx;
	}
}

void Enemy::Update_healthNcolor(Bullet_player* bullet)
{
	if (bullet != nullptr)
	{
		//collision check
		if ((bullet->GetX() >= x) &&
			(bullet->GetX() <= x + size) &&
			(bullet->GetY() >= y) &&
			(bullet->GetY() <= y + size))
		{
			//lower enemy health
			if (hp_current > 0)
			{
				hp_current -= Bullet_player::damage;
			}

			//change color based on health
			float damage_effect = ( 1 - ((1 - (hp_current / hp_total)) / 1.5) );
			color_body_current.SetR(color_body_original.GetR() * damage_effect);
			color_body_current.SetG(color_body_original.GetG() * damage_effect);
			color_body_current.SetB(color_body_original.GetB() * damage_effect);
											  
			color_head_current.SetR(color_head_original.GetR() * damage_effect);
			color_head_current.SetG(color_head_original.GetG() * damage_effect);
			color_head_current.SetB(color_head_original.GetB() * damage_effect);

			//bullet collision toggle
			bullet->colliding = true;
		}
	}
}


int Enemy::GetX()
{
	return x;
}
int Enemy::GetY()
{
	return y;
}
float Enemy::GetCurrentHP()
{
	return hp_current;
}

void Enemy::Fire(int player_x, int player_y)
{
	for (int i = 0; i < mag_total; i++)
	{
		if (bullet[i] == nullptr)
		{
			bullet[i] = new Bullet_enemy( (x + (size / 2)), (y + (size / 2)), 
										(player_x + (Player::size / 2)), 
										(player_y + (Player::size / 2)) );
			return;
		}
	}
}

void Enemy::Update_bullets(Bullet_enemy* bullet[])
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


void Enemy::Draw(Graphics& gfx, int player_x, int player_y) const
{
	//(temporary) assuming constant size of 60 including head
	int half2 = size / 2;
	int half1 = (size / 2) - 1;

		//body of enemy, a circle of 40 size
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
	//update the direction the enemy faces to toward the player
	float to_playerx = (x + (size/2)) - player_x;
	float to_playery = (y + (size/2)) - player_y;

	//special case
	if (to_playerx == 0)
	{
		if (to_playery >= 0)
		{
			//points up
			int i = 0;
			while (i < 10)
			{
				gfx.PutPixel(x + 19, y + i, color_head_current);
				gfx.PutPixel(x + 20, y + i, color_head_current);
				i++;
			}
		}
		else
		{
			//points down
			int j = size - 10;
			while (j < size)
			{
				gfx.PutPixel(x + 19, y + j, color_head_current);
				gfx.PutPixel(x + 20, y + j, color_head_current);
				j++;
			}
		}
		return;
	}


	float facing = to_playery / to_playerx;
	

	//quadrants
	//top left corner (x+ y+)
	if (to_playerx > 0 && to_playery > 0)
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
		else if (facing < (1 / tan67_5)) //face left
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
	if (to_playerx < 0 && to_playery < 0)
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
	if (to_playerx > 0 && to_playery < 0)
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
	if (to_playerx < 0 && to_playery > 0)
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

