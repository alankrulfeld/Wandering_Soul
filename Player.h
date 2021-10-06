#pragma once
#include "Textures.h"
class Player {
private:
	bool isAlive = false;
	float posX;
	float posY;
	float velocityY;
	float accelerationY;
	float radius;
	float gravity;
public:
	Player();
	~Player();
	void SetAlive(bool isAlive);
	bool GetAlive();
	void SetPositionX(float positionX);
	float GetPositionX();
	void SetPositionY(float positionY);
	float GetPositionY();
	float GetRadius();
	void Movement();
};

