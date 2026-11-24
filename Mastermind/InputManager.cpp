#include "InputManager.h"

char InputManager::GetKey() {
	char ch = _getch();

	return ch;
}

void InputManager::GetCombination(char guess[4]) {
	std::string input;

	while (true) {
		std::cout << "Entrez une combinaison de 4 couleurs (n, r, o, v, ex. nrov) : ";
		if (std::cin >> input && input.size() == 4) {
			bool valid = true;

			for (int i = 0; i < 4; ++i) {
				char c = static_cast<char>(std::toupper(static_cast<unsigned char>(input[i])));
				if (c != 'N' && c != 'R' && c != 'O' && c != 'V' && c != 'B' && c != 'J') {
					valid = false;
					break;
				}
				guess[i] = c;
			}

			if (valid) {
				return;
			}
		}

		std::cout << "Saisie invalide. ";
		std::cin.clear();
		std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
	}
}