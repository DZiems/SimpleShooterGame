#pragma once
#include "Colors.h"
#include "Graphics.h"
#include "Bullet_enemy.h"
#include "Bullet_player.h"
#include "Player.h"

class Enemy
{
public:

	Enemy();

	int GetX();
	int GetY();
	float GetCurrentHP();

	void Update_healthNcolor(Bullet_player* bullet);
	void Update_mvmnt();

	void Fire(int player_x, int player_y);
	void Update_bullets(Bullet_enemy* bullet[]);

	static constexpr int size = 60;
	//WARNING: if you raise mag_total, there is no implementation for delaying shots in quick succession
	//enemies will fire one bullet per frame, so this meg_total is intended to stay 1 for now
	static constexpr int mag_total = 1;
	static constexpr float hp_total = 50;
	static constexpr float tan67_5 = 2.414214;
	static constexpr float speed = 2.0f;
	void Draw(Graphics& gfx, int player_x, int player_y) const;
	

	Bullet_enemy* bullet[mag_total];

private:
	float x, y;
	float vx, vy;	
	float hp_current;
	
	

	Color const color_body_original = Colors::Red;
	Color color_body_current;
	Color const color_head_original = Colors::LightGray;
	Color color_head_current;
};