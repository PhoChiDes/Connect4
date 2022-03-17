#include <iostream>
#include "GameMechanics.h"


int main()
{
	GameMechanics Game;
	GameMechanics::playerInfo playerOne, playerTwo;
	char board[9][10];
	int trueWidth = 7;
	int trueLength = 6;
	int dropChoice, win, full, again;

	std::cout << "Let's Play Connect 4" << std::endl << std::endl;
	std::cout << "Player One please enter your name: ";
	std::cin >> playerOne.playerName;
	playerOne.playerID = 'X';
	std::cout << "Player Two please enter your name: ";
	std::cin >> playerTwo.playerName;
	playerTwo.playerID = 'O';

	full = 0;
	win = 0;
	again = 0;
	Game.DisplayBoard(board);
	do
	{
		dropChoice = Game.PlayerDrop(board, playerOne);
		Game.CheckBellow(board, playerOne, dropChoice);
		Game.DisplayBoard(board);
		win = Game.CheckFour(board, playerOne);
		if (win == 1)
		{
			Game.PlayerWin(playerOne);
			again = Game.restart(board);
			if (again == 2)
			{
				break;
			}
		}

		dropChoice = Game.PlayerDrop(board, playerTwo);
		Game.CheckBellow(board, playerTwo, dropChoice);
		Game.DisplayBoard(board);
		win = Game.CheckFour(board, playerTwo);
		if (win == 1)
		{
			Game.PlayerWin(playerTwo);
			again = Game.restart(board);
			if (again == 2)
			{
				break;
			}
		}
		full = Game.FullBoard(board);
		if (full == 7)
		{
			std::cout << "The board is full, it is a draw!" << std::endl;
			again = Game.restart(board);
		}

	} while (again != 2);



	return 0;
}

