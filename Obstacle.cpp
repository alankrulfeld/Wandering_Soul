#include "Obstacle.h"

Obstacle::Obstacle()
{
	posY = GetRandomValue(GetScreenHeight() * 0.50f, GetScreenHeight() - GetScreenHeight() * 0.25f);
}

Obstacle::~Obstacle()
{
}

void Obstacle::SetActive(bool isActive)
{
	this->isActive = isActive;
}

bool Obstacle::GetActive()
{
	return isActive;
}

void Obstacle::SetPositionX(float positionX)
{
	posX = positionX;
}

float Obstacle::GetPositionX()
{
	return posX;
}

void Obstacle::SetPositionY(float positionY)
{
	posY = positionY;
}

float Obstacle::GetPositionY()
{
	return posY;
}

float Obstacle::GetWidth()
{
	return width;
}

float Obstacle::GetHeight()
{
	return height;
}

void Obstacle::Movement()
{
	posX -= 100 * GetFrameTime();
	if (posX + width <= 0)
	{
		posX = GetScreenWidth();
		posY = GetRandomValue(GetScreenHeight() * 0.50f, GetScreenHeight() - GetScreenHeight() * 0.25f);
	}
}


