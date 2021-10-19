#pragma once
#include <string>
#include "Textures.h"
#include "GameManager.h"

using namespace std;

class Intro
{
private:
	Music introLogoAudio;
	Texture2D logoTexture;
	Textures* logo;
	GameManager* GM;
	bool isOn;
public:
	const int screenWidth = 1366;
	const int screenHeight = 768;
	Intro();
	~Intro();
	void StartIntro();
};

