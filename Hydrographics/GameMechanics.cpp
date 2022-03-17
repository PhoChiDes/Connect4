#include "GameMechanics.h"
#include <iostream>

int GameMechanics::PlayerDrop(char board[][10], playerInfo activePlayer)
{
	int dropChoice;
	do
	{
		std::cout << activePlayer.playerName << "'s Turn ";
		std::cout << "Please enter a number between 1 and 7: ";
		std::cin >> dropChoice;

		while (board[1][dropChoice] == 'X' || board[1][dropChoice] == 'O')
		{
			std::cout << "That row is full, please enter a new row: ";
			std::cin >> dropChoice;
		}

	} while (dropChoice < 1 || dropChoice > 7);

	return dropChoice;
}


int GameMechanics::CheckFour(char board[][10], playerInfo activePlayer)
{
	char XO;
	int win;

	XO = activePlayer.playerID;
	win = 0;

	for (int i = 8; i >= 1; --i)
	{

		for (int ix = 9; ix >= 1; --ix)
		{

			if (board[i][ix] == XO &&
				board[i - 1][ix - 1] == XO &&
				board[i - 2][ix - 2] == XO &&
				board[i - 3][ix - 3] == XO)
			{
				win = 1;
			}


			if (board[i][ix] == XO &&
				board[i][ix - 1] == XO &&
				board[i][ix - 2] == XO &&
				board[i][ix - 3] == XO)
			{
				win = 1;
			}

			if (board[i][ix] == XO &&
				board[i - 1][ix] == XO &&
				board[i - 2][ix] == XO &&
				board[i - 3][ix] == XO)
			{
				win = 1;
			}

			if (board[i][ix] == XO &&
				board[i - 1][ix + 1] == XO &&
				board[i - 2][ix + 2] == XO &&
				board[i - 3][ix + 3] == XO)
			{
				win = 1;
			}

			if (board[i][ix] == XO &&
				board[i][ix + 1] == XO &&
				board[i][ix + 2] == XO &&
				board[i][ix + 3] == XO)
			{
				win = 1;
			}
		}

	}

	return win;
}

void GameMechanics::CheckBellow(char board[][10], playerInfo activePlayer, int dropChoice)
{
	int length, turn;
	length = 6;
	turn = 0;

	do
	{
		if (board[length][dropChoice] != 'X' && board[length][dropChoice] != 'O')
		{
			board[length][dropChoice] = activePlayer.playerID;
			turn = 1;
		}
		else
			--length;
	} while (turn != 1);


}

void GameMechanics::DisplayBoard(char board[][10])
{
	int rows = 6, columns = 7, i, ix;

	for (i = 1; i <= rows; i++)
	{
		std::cout << "|";
		for (ix = 1; ix <= columns; ix++)
		{
			if (board[i][ix] != 'X' && board[i][ix] != 'O')
				board[i][ix] = '*';

			std::cout << board[i][ix];

		}

		std::cout << "|" << std::endl;
	}

}

int GameMechanics::FullBoard(char board[][10])
{
	int full;
	full = 0;
	for (int i = 1; i <= 7; ++i)
	{
		if (board[1][i] != '*')
			++full;
	}

	return full;
}

void GameMechanics::PlayerWin(playerInfo activePlayer)
{	
    std::cout << std::endl << activePlayer.playerName << " Connected Four, You Win!" << std::endl;
}

int GameMechanics::restart(char board[][10])
{
	int restart;

	std::cout << "Would you like to restart? Yes(1) No(2): ";
	std::cin >> restart;
	if (restart == 1)
	{
		for (int i = 1; i <= 6; i++)
		{
			for (int ix = 1; ix <= 7; ix++)
			{
				board[i][ix] = '*';
			}
		}
	}
	else
		std::cout << "Goodbye!" << std::endl;
	return restart;
}
