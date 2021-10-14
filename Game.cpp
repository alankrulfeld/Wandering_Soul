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
	soulAnimationTexture = LoadTexture("assets/SoulAnimation1.png");
	soulAnimationTexture.width /= 7;
	soulAnimationTexture.height /= 7;
	soulAnimation = new Textures();
	background = LoadTexture("assets/bg.png");
	far = LoadTexture("assets/far1.png");
	mid = LoadTexture("assets/mid.png");
	close = LoadTexture("assets/close.png");
	background.width = GetScreenWidth();
	background.height = GetScreenHeight();
	far.width = GetScreenWidth()/2;
	far.height = GetScreenHeight()/2;
	mid.width = GetScreenWidth()/2;
	mid.height = GetScreenHeight()/2;
	close.width = GetScreenWidth()/2;
	close.height = GetScreenHeight()/2;
	scrollingBack = 0.0f;
	scrollingMid = 0.0f;
	scrollingFore = 0.0f;
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
		scrollingBack -= 0.1f;
		scrollingMid -= 0.5f;
		scrollingFore -= 1.0f;

		if (scrollingBack <= -far.width * 2) scrollingBack = 0;
		if (scrollingMid <= -mid.width * 2) scrollingMid = 0;
		if (scrollingFore <= -close.width * 2) scrollingFore = 0;
	}
	
}

void Game::DrawGame() {
	BeginDrawing();
	ClearBackground(DARKBLUE);

	DrawTextureEx(background, { 0,0 }, 0, 2, WHITE);
	DrawTextureEx(far, { scrollingBack, 0 }, 0.0f, 2.0f, WHITE);
	DrawTextureEx(far, { far.width * 2 + scrollingBack, 0 }, 0.0f, 2.0f, WHITE);

	DrawTextureEx(mid, { scrollingMid, 0 }, 0.0f, 2.0f, WHITE);
	DrawTextureEx(mid, { mid.width * 2 + scrollingMid, 0 }, 0.0f, 2.0f, WHITE);

	DrawTextureEx(close, { scrollingFore, 0 }, 0.0f, 2.0f, WHITE);
	DrawTextureEx(close, { close.width * 2 + scrollingFore, 0 }, 0.0f, 2.0f, WHITE);

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
