#pragma once
#include "Textures.h"

class Obstacle
{
private:
	float posX;
	float posY;

	const float width = 80;
	const float height = GetScreenHeight() * 0.65f;
	bool isActive;
public:
	Obstacle();
	~Obstacle();
	void SetActive(bool isActive);
	bool GetActive();
	void SetPositionX(float positionX);
	float GetPositionX();
	void SetPositionY(float positionY);
	float GetPositionY();
	float GetWidth();
	float GetHeight();
	void Movement();
};

