#include "InputManager.h"

char InputManager::GetKey() {
	char ch = _getch();

	return ch;
}