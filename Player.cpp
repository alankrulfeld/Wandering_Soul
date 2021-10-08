#include "Player.h"

Player::Player() {
    posX = GetScreenWidth() / 4;
    posY = GetScreenHeight() / 2;
    radius = 20;
    velocityY = 0;
    accelerationY = 0;
    gravity = 300;
    isAlive = true;
}

Player::~Player() {
}

void Player::SetAlive(bool isAlive) {
    this->isAlive = isAlive;
}

bool Player::GetAlive() {
    return isAlive;
}

void Player::SetPositionX(float positionX) {
    posX = positionX;
}

float Player::GetPositionX() {
    return posX;
}

void Player::SetPositionY(float positionY) {
    posY = positionY;
}

float Player::GetPositionY() {
    return posY;
}

float Player::GetRadius() {
    return radius;
}

void Player::Movement() {

    if ((IsKeyPressed(KEY_SPACE) || IsMouseButtonPressed(MOUSE_LEFT_BUTTON))) {
        accelerationY = 0;
        velocityY = -gravity / 2;
    }
    else {
        accelerationY += gravity * GetFrameTime();
    }

    if (accelerationY >= gravity) {
        accelerationY = gravity;
    }

    if (velocityY < 0) {
        velocityY += accelerationY * 2 * GetFrameTime();
    }
    else {
        velocityY += accelerationY * GetFrameTime();
    }

    if((velocityY > 0 && posY <= GetScreenHeight()-radius) || (velocityY < 0 && posY >= radius))
    posY += velocityY * GetFrameTime();
}
