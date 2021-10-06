#pragma once
class Player {
private:
	bool isAlive = false;
	float posX;
	float posY;
public:
	Player();
	~Player();
	void SetAlive(bool isAlive);
	bool GetAlive();
	void SetPositionX(float positionX);
	float GetPositionX();
	void SetPositionY(float positionY);
	float GetPositionY();
	void Movement();
};

