#include "Menu.h"

Menu::Menu() {
	menuInited = false;
	goToGame = false;
	goToCredits = false;
	exitGame = false;
}

Menu::~Menu() {
}

void Menu::Init() {
	SetTargetFPS(60);
	InitAudioDevice();
	scrolling = 0.0f;
	menuInited = true;
	button0Area = { 515 * windowReSizeWidth  ,320 * windowReSizeHeight  ,320 * windowReSizeWidth  ,120 * windowReSizeHeight };
	button1Area = { 545 * windowReSizeWidth  ,485 * windowReSizeHeight  ,260 * windowReSizeWidth  ,60 * windowReSizeHeight };
	button2Area = { 545 * windowReSizeWidth  ,585 * windowReSizeHeight  ,260 * windowReSizeWidth ,60 * windowReSizeHeight };
	button3Area = { 545 * windowReSizeWidth  ,685 * windowReSizeHeight  ,260 * windowReSizeWidth  ,60 * windowReSizeHeight };
}

void Menu::Input() {
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), button0Area)) {
		goToGame = true;
	}
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), button1Area)) {
		if (GetScreenWidth() == 1366) {
			SetWindowSize(1600, 900);
		}
		else {
			SetWindowSize(1366, 768);
		}
	}
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), button2Area)) {
		goToCredits = true;
	}
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), button3Area)) {
		exitGame = true;
	}
}

void Menu::Update() {
	windowReSizeWidth = GetScreenWidth() / screenWidth;
	windowReSizeHeight = GetScreenHeight() / screenHeight;
}

void Menu::Draw() {
	BeginDrawing();
	ClearBackground(RAYWHITE);
	DrawRectangle(button0Area.x,button0Area.y,button0Area.width,button0Area.height,RED);
	DrawRectangle(button1Area.x, button1Area.y, button1Area.width, button1Area.height, RED);
	DrawRectangle(button2Area.x, button2Area.y, button2Area.width, button2Area.height, RED);
	DrawRectangle(button3Area.x, button3Area.y, button3Area.width, button3Area.height, RED);
	EndDrawing();
}

bool Menu::GetInited() {
	return menuInited;
}

bool Menu::ExitMenuGoToGame() {
	return goToGame;
}

bool Menu::ExitMenuGoToShop() {
	return goToShop;
}

bool Menu::ExitMenuGoToCredits() {
	return goToCredits;
}

bool Menu::ExitMenuGoToOptions() {
	return goToOptions;
}

bool Menu::ExitGame() {
	return exitGame;
}

void Menu::DeInit() {
	menuInited = false;
}