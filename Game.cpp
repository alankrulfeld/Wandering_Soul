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
	return false;
}

bool Game::GoToGame() {
	return false;
}
