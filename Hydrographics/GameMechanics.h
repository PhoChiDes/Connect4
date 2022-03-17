#pragma once
class GameMechanics{
public:
	struct playerInfo
	{
		char playerName[81];
		char playerID;
	};
	int PlayerDrop(char board[][10], playerInfo activePlayer);
	void CheckBellow(char board[][10], playerInfo activePlayer, int dropChoice);
	void DisplayBoard(char board[][10]);
	int CheckFour(char board[][10], playerInfo activePlayer);
	int FullBoard(char board[][10]);
	void PlayerWin(playerInfo activePlayer);
	int restart(char board[][10]);
};

