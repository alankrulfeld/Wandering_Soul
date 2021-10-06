#include "Menu.h"

Menu::Menu() {
	menuInited = false;
	goToGame = false;
	goToCredits = false;
}

Menu::~Menu() {
}

void Menu::Init() {
	SetTargetFPS(60);
	InitAudioDevice();
	scrolling = 0.0f;
	menuInited = true;
}

void Menu::Input() {
	
}

void Menu::Update() {
	windowReSizeWidth = GetScreenWidth() / screenWidth;
	windowReSizeHeight = GetScreenHeight() / screenHeight;
}

void Menu::Draw() {
	BeginDrawing();
	ClearBackground(RAYWHITE);
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


