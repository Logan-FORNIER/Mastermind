#include "InputManager.h"

char InputManager::GetKey() {
	char ch = _getch();

	return ch;
}

int InputManager::GetNumber() {
	int number;
	std::cin >> number;

	if (number > 4444 || number < 0001) {
		return 1;
	}

	return 0;
}