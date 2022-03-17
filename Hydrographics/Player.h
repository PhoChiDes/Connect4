#pragma once
#include <string>

class Player{
private:
	std::string _Name;
	int _Wins;
public:
	void AddWin();
	std::string GetName();
};

