#include "Obstacle.h"

Obstacle::Obstacle() {
	
}

Obstacle::~Obstacle() {
}

void Obstacle::SetActive(bool isActive) {
	this->isActive = isActive;
}

bool Obstacle::GetActive() {
	return isActive;
}

void Obstacle::SetPositionX(float positionX) {
	posX = positionX;
}

float Obstacle::GetPositionX() {
	return posX;
}

void Obstacle::SetPositionY(float positionY) {
	posY = positionY;
}

float Obstacle::GetPositionY() {
	return posY;
}

float Obstacle::GetWidth() {
	return width;
}

void Obstacle::Movement() {
	posX += 50 * GetFrameTime();
}

