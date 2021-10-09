#include "Game.h"

Game::Game() {
	player = new Player();
	for (int i = 0; i < 3; i++) {
		obstacle[i] = new Obstacle();
		obstacle[i]->SetPositionX(GetScreenWidth() + 500 * i);
	}
	buttonP = { (float)GetScreenWidth() - 100, 0, 100, 100 };
	buttonResumeArea = {(float)GetScreenWidth()/2-200,(float)GetScreenHeight()/2,100,50};
	buttonExitArea = { (float)GetScreenWidth() / 2 + 200,(float)GetScreenHeight() / 2,100,50 };
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
	if (isPaused) {

	}
	if (!isPaused) {
		player->Movement();
	}
}

void Game::UpdateGame() {
	if (!isPaused) {
		if (CheckCollisionPointRec(GetMousePosition(), buttonP) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			isPaused = !isPaused;
		}
		for (int i = 0; i < 3; i++) {
			obstacle[i]->Movement();
		}
		CheckCollision();
		if (!(player->GetAlive())) {
			goToGame = true;
		}
	}
	else if (isPaused) {
		if (CheckCollisionPointRec(GetMousePosition(), buttonP) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			isPaused = !isPaused;
		}
		if (CheckCollisionPointRec(GetMousePosition(), buttonResumeArea) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			isPaused = !isPaused;
		}
		if (CheckCollisionPointRec(GetMousePosition(), buttonExitArea) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			goToMenu = true;
		}
	}
}

void Game::DrawGame() {
	BeginDrawing();
	ClearBackground(DARKBLUE);
	DrawCircle(player->GetPositionX(), player->GetPositionY(), player->GetRadius(), YELLOW);
	for (int i = 0; i < 3; i++) {
		DrawRectangle(obstacle[i]->GetPositionX(), obstacle[i]->GetPositionY(), obstacle[i]->GetWidth(), obstacle[i]->GetHeight(), GREEN);
		DrawRectangle(obstacle[i]->GetPositionX(), 0, obstacle[i]->GetWidth(), obstacle[i]->GetHeight() - (GetScreenHeight() - obstacle[i]->GetPositionY()), GREEN);
	}
	if (isPaused) {
		DrawRectangle(buttonResumeArea.x, buttonResumeArea.y, buttonResumeArea.width, buttonResumeArea.height, RED);
		DrawRectangle(buttonExitArea.x, buttonExitArea.y, buttonExitArea.width, buttonExitArea.height, RED);
	}
	DrawRectangle(buttonP.x, buttonP.y, buttonP.width, buttonP.height, RED);
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
