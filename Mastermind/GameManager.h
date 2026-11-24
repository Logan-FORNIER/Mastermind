#pragma once
#include "pch.h"
#include "InputManager.h"
#include "RoundManager.h"

class GameManager
{
private:
	InputManager im;
	RoundManager rm;

	bool isRunning;
	char secretCombination[4];

public:
	void SecretCombinationGenerator();
	void Loop();
	void Menu();
	void Initialize();
	void CreditMenu();
};

	