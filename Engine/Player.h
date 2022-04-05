#pragma once
#include "Graphics.h"
#include "Reticle.h"
#include "Colors.h"
#include "Bullet_player.h"
#include "Bullet_enemy.h"
#include "Enemy.h"
#include <cmath>
#include "Keyboard.h"
#include "Mouse.h"

//this will be drawn as a box for now
class Player
{
public:
	Player();

	int GetX();
	int GetY();
	float GetCurrentHP();

	void Update_mvmnt(const Keyboard& kbd);
	void Update_healthNcolor(Bullet_enemy* bullet[]);

	//fully replenishes hp
	void Recover();
	//sets x and y back to middle
	void ResetSpawnPt();

	void Fire(Reticle ret, const Mouse& mouse, bool& lefclick_buffer);
	void Update_Bullets(Bullet_player* bullet[]);

	//draws the player (so that it points toward the reticle)
	void Draw(Graphics& gfx, Reticle& ret);
	void DrawHUD(Graphics& gfx);

	static constexpr int size = 60;
	static constexpr float hp_total = 100;
	static constexpr int mag_total = 4;
	static constexpr float tan67_5 = 2.414214;
	static constexpr float speed = 3.0f;
	static constexpr float frictionFactor = 0.02f;
	static constexpr int spawnX = (Graphics::ScreenWidth - 1 - (size/2)) / 2;
	static constexpr int spawnY = (Graphics::ScreenHeight - 1 - (size / 2)) / 2;

	Bullet_player* bullet[mag_total];
private:
	
	float x, y;
	float vx, vy;

	float hp_current;
	int mag_current;

	Color const color_body_original = Colors::LightGray;
	Color color_body_current;
	Color const color_head_original = Colors::Blue;
	Color color_head_current;
};

