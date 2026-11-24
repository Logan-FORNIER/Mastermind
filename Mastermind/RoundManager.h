#pragma once
#include "pch.h"

class RoundManager
{
private:
	int round = 0;
	int roundMax = 10;

public:
	int GetRound() const { return round; }
	int GetMaxRound() const { return roundMax; }
	int IncreaseRond();
	int SetRound();
};

