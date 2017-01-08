#include "HUD.h"
#include "Actor.h"
#include "Canvas.h"	

HUD::HUD() {}

HUD::HUD(Canvas &canvas, Player &player, Player& player2)
{
	_player1 = player;
	_player2 = player2;
	_healthBarSprite1 = SpriteActor(canvas, "Content/Sprites/HealthBar.png", 0, 40, 64, 8, 0, 0);
	_healthBarSprite2 = SpriteActor(canvas, "Content/Sprites/HealthBar.png", 0, 40, 64, 8, 674, 585);
	_currentHealthBar1 = SpriteActor(canvas, "Content/Sprites/HealthBar.png", 0, 25, 39, 5, 48, 1);
	_currentHealthBar2 = SpriteActor(canvas, "Content/Sprites/HealthBar.png", 0, 25, 39, 5, 722, 586);
}

void HUD::update(int elapsedTime)
{
	//Calculate the width of the health bar
	//100% = 39 px (width)
	float numPlayer1 = (float)_player1.getCurrentHealthPlayer1() / _player1.getMaxHealthPlayer1();
	_currentHealthBar1.setSourceRectW(std::floor(numPlayer1 * 39));

	float numPlayer2 = (float)_player2.getCurrentHealthPlayer2() / _player2.getMaxHealthPlayer2();
	_currentHealthBar2.setSourceRectW(std::floor(numPlayer2 * 39));
}

void HUD::draw(Canvas &canvas)
{
	_healthBarSprite1.draw(canvas);
	_healthBarSprite2.draw(canvas);
	_currentHealthBar1.draw(canvas);
	_currentHealthBar2.draw(canvas);

}