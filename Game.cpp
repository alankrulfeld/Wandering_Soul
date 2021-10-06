#include "Game.h"

Game::Game() {
	player = new Player();
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
	
}

void Game::DrawGame() {
	BeginDrawing();
	ClearBackground(SKYBLUE);
	DrawCircle(player->GetPositionX(), player->GetPositionY(), player->GetRadius() ,BLUE);
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
