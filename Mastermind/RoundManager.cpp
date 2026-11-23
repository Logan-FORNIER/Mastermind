#include "RoundManager.h"

int RoundManager::IncreaseRond() {
	if (round < roundMax) {
		++round;
	}

	if (round >= roundMax) {
		return 1;
	}

	return 0;
}