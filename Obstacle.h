#pragma once
#include "Textures.h"

class Obstacle {
private:
	float posX;
	float posY;
	float width;
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
	void Movement();
};

