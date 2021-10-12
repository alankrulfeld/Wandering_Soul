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
	goToGame = false;
	soulAnimationTexture = LoadTexture("assets/soulAnimation.png");
	soulAnimationTexture.width /= 12;
	soulAnimationTexture.height /= 12;
	soulAnimation = new Textures();
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
	else if (!isPaused) {
		if (CheckCollisionPointRec(GetMousePosition(), buttonP) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			isPaused = !isPaused;
		}
		else {
			player->Movement();
		}
		for (int i = 0; i < 3; i++) {
			obstacle[i]->Movement();
		}
	}
}

void Game::UpdateGame() {
	if (!isPaused) {
		CheckCollision();
		if (!(player->GetAlive())) {
			goToGame = true;
		}
		player->UpdateAnimation(soulAnimation,soulAnimationTexture);
	}
}

void Game::DrawGame() {
	BeginDrawing();
	ClearBackground(DARKBLUE);
	DrawText("Space Bar or Left Click to Jump", GetScreenWidth() / 2 - TextLength("Space Bar or Left Click to Jump") * 10 / 2, GetScreenHeight() / 2, 20, WHITE);
	DrawCircle(player->GetPositionX(), player->GetPositionY(), player->GetRadius(), YELLOW);
	DrawTextureRec(soulAnimationTexture, player->GetRec(),soulAnimation->GetPosition(), WHITE);
	for (int i = 0; i < 3; i++) {
		DrawRectangle(obstacle[i]->GetPositionX(), obstacle[i]->GetPositionY(), obstacle[i]->GetWidth(), obstacle[i]->GetHeight(), GREEN);
		DrawRectangle(obstacle[i]->GetPositionX(), 0, obstacle[i]->GetWidth(), obstacle[i]->GetHeight() - (GetScreenHeight() - obstacle[i]->GetPositionY()), GREEN);
	}
	if (isPaused) {
		DrawRectangle(buttonResumeArea.x, buttonResumeArea.y, buttonResumeArea.width, buttonResumeArea.height, RED);
		DrawText("Resume", buttonResumeArea.x, buttonResumeArea.y, 20, WHITE);
		DrawRectangle(buttonExitArea.x, buttonExitArea.y, buttonExitArea.width, buttonExitArea.height, RED);
		DrawText("Exit", buttonExitArea.x, buttonExitArea.y, 20, WHITE);
	}
	DrawRectangle(buttonP.x, buttonP.y, buttonP.width, buttonP.height, RED);
	DrawText("Pause", buttonP.x, buttonP.y, 20, WHITE);
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
