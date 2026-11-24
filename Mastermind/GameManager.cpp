#pragma once
#include "GameManager.h"

/*

 n = Noir;
 b = Bleu;
 r = Rouge;
 o = Orange;
 v = Vert;
 j = Jaune;

*/

void GameManager::SecretCombinationGenerator() {
	char colors[6] = { 'N', 'R', 'O', 'V', 'B', 'J'};

	for (int i = 0; i < 4; i++) {
		secretCombination[i] = colors[rand() % 4];
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

	rm.SetRound();
	SecretCombinationGenerator();

	Loop();
}

void GameManager::Loop() {
	isRunning = true;
	char guess[4] = { 0 };

	while (isRunning) {
		system("cls");

		int count = 0;
		im.GetCombination(guess);

		for (int i = 0; i < 4; ++i) {
			if (guess[i] != secretCombination[i]) {
				break;
			}
		}

		for (int i = 0; i < 4; i++) {
			if (guess[i] == secretCombination[i]) {
				count++;
			}
		}

		if (count == 4) {
			std::cout << "Bien jouer ! le code couleurs secret etait : ";
			for (int i = 0; i < 4; ++i) {
				std::cout << secretCombination[i];
			}
			std::cout << "\n";
			isRunning = false;
		}
		else {
			std::cout << "Ce n'est pas la bonne combinaison ! " << count << " sont bien mis, il te reste " << (rm.GetMaxRound() - rm.GetRound()) - 1 << std::endl;
			if (rm.IncreaseRond()) {
				std::cout << "Perdu ! Nombre maximum de manches atteint. Le code etait : ";
				for (int i = 0; i < 4; ++i) {
					std::cout << secretCombination[i];
				}
				std::cout << "\n";
				isRunning = false;
			}
			system("pause");
		}
	}
}