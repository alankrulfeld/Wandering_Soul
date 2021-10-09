#pragma once
#include "Player.h"
#include "Obstacle.h"

class Game {
private:
	bool gameInited;
	bool goToMenu;
	bool replay;
	bool isPaused;
	bool goToGame;
	Player* player;
	Obstacle* obstacle[3];
	Rectangle buttonP;
	Rectangle buttonResumeArea;
	Rectangle buttonExitArea;
public:
	const int screenWidth = 1366;
	const int screenHeight = 768;
	float currentScreenWidth = GetScreenWidth();
	float currentScreenHeight = GetScreenHeight();
	float windowReSizeWidth = currentScreenWidth / screenWidth;
	float windowReSizeHeight = currentScreenHeight / screenHeight;
	Game();
	~Game();
	bool GetInited();
	void InitGame();         // Initialize game
	void InputGame();
	void UpdateGame();       // Update game (one frame)
	void DrawGame();         // Draw game (one frame)
	void DeInitGame();       // Unload game
	void UpdateDrawFrame();  // Update and Draw (one frame)
	bool GoToMenu();
	bool GoToGame();
	void CheckCollision();
};

