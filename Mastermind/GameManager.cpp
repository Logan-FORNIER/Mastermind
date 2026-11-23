#pragma once
#include "GameManager.h"

/*

 0 = Noir;
 1 = Rouge;
 2 = Orange;
 3 = Vert;

*/

void GameManager::SecretCombinationGenerator() {
	for (int i = 0; i < 4; i++) {
		secretCombination[i] = rand() % 4;
	}
}

void GameManager::CreditMenu() {
	std::cout << "========================================================================" << std::endl;
	std::cout << "                          CREDITS DU PROJET                             " << std::endl;
	std::cout << "========================================================================" << std::endl;
	std::cout << "                                                                        " << std::endl;
	std::cout << "   ______    _             _____   _  __     ____                       " << std::endl;
	std::cout << "  |  ____|  | |           |_   _| | |/ /   |  __  |                     " << std::endl;
	std::cout << "  | |__     | |             | |   | ' /    | |  | |                     " << std::endl;
	std::cout << "  |  __|    | |             | |   |  <|    | |  | |                     " << std::endl;
	std::cout << "  | |____   | |____   __   _| |_  | ._ \\   | |__| |                     " << std::endl;
	std::cout << "  |______|  |______| |__| |_____| |_| \\_\\  | ____ |                     " << std::endl;
	std::cout << "                                                                        " << std::endl;
	std::cout << "========================================================================" << std::endl;
	std::cout << "                     Developpe par EL_IKO                               " << std::endl;
	std::cout << "========================================================================" << std::endl;
	system("pause");
}

void GameManager::Menu() {
	std::cout << "[ Menu ]\n";
	std::cout << "P: Jouer, Q: Quitter, C: Credits\n";
	char MenuChoice = im.GetKey();

	switch (MenuChoice)
	{
	case 'p':
		std::cout << "Initialisation du jeu ...\n\n";
		Initialize();
		break;
	case 'q':
		std::cout << "Fermeture du jeu\n";
		isRunning = false;
		break;
	case 'c':
		CreditMenu();
		break;
	}
}

void GameManager::Initialize() {
	srand(time(NULL));

	SecretCombinationGenerator();

	Loop();
}

void GameManager::Loop() {
	isRunning = true;

	while (isRunning) {
		system("cls");

		if (im.GetNumber() == secretCombination) {
			isRunning = false;
		}
	}
}