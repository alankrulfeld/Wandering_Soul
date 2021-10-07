#include "Game.h"

Game::Game() {
	player = new Player();
	for (int i = 0; i < 3; i++) {
		obstacle[i] = new Obstacle();
		obstacle[i]->SetPositionX(GetScreenWidth() + 500 * i);
	}
}

Game::~Game() {
	delete player;
	for (int i = 0; i < 3; i++) {
		delete obstacle[i];
	}
}

bool Game::GetInited() {
	return gameInited;
}

void Game::InitGame() {
	gameInited = true;
}

void Game::InputGame() {
	player->Movement();
}

void Game::UpdateGame() {
	for (int i = 0; i < 3; i++) {
		obstacle[i]->Movement();
	}
	CheckCollision();
	if(!(player->GetAlive())){
		goToGame = true;
	}
}

void Game::DrawGame() {
	BeginDrawing();
	ClearBackground(DARKBLUE);
	DrawCircle(player->GetPositionX(), player->GetPositionY(), player->GetRadius() , YELLOW);
	for (int i = 0; i < 3; i++) {
		DrawRectangle(obstacle[i]->GetPositionX(), obstacle[i]->GetPositionY(), obstacle[i]->GetWidth(), obstacle[i]->GetHeight(), GREEN);
		DrawRectangle(obstacle[i]->GetPositionX(), 0, obstacle[i]->GetWidth(), obstacle[i]->GetHeight() - (GetScreenHeight() - obstacle[i]->GetPositionY()), GREEN);
	}
	EndDrawing();
}

void Game::DeInitGame() {
}

void Game::UpdateDrawFrame() {
	InputGame();
	UpdateGame();
	DrawGame();
}

bool Game::GoToMenu() {
	return goToMenu;
}

bool Game::GoToGame() {
	return goToGame;
}

void Game::CheckCollision() {
	for (int i = 0; i < 3; i++) {
		if (((player->GetPositionY() + player->GetRadius()) >= obstacle[i]->GetPositionY()) && ((player->GetPositionX() + player->GetRadius()) >= obstacle[i]->GetPositionX()) && ((player->GetPositionX() - player->GetRadius()) <= (obstacle[i]->GetPositionX() + obstacle[i]->GetWidth()))) {
			player->SetAlive(false);
		}
		if (((player->GetPositionY() - player->GetRadius()) <= (obstacle[i]->GetHeight() - (GetScreenHeight() - obstacle[i]->GetPositionY()))) && ((player->GetPositionX() + player->GetRadius()) >= obstacle[i]->GetPositionX()) && ((player->GetPositionX() - player->GetRadius()) <= (obstacle[i]->GetPositionX() + obstacle[i]->GetWidth()))) {
			player->SetAlive(false);
		}
	}
}
