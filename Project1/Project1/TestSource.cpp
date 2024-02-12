#include <iostream>
#include "TestHeader.h"
#include <vector>
#include <random>

//TicTacToe game

class Board
{
private:
	std::vector<std::vector<char>> GameBoard;


public:
	Board() : GameBoard(3, std::vector<char>(3, '_')) {}


	char screenMenu()
	{
		int choice{ 0 };
		char playerSym{ ' ' };

		do {
			coloring::colorText("Welcome to TicTacToe", "Black", "Cyan");
			coloring::colorText("1. Select X", "Black","Red");
			coloring::colorText("2. Select O", "Black", "Blue");
			coloring::colorText("3. Exit", "Black", "Green");
			std::cin >> choice;

			switch (choice) {
			case 1:
				playerSym = 'X';
				break;
			case 2:
				playerSym = 'O';
				break;
			case 3:
				return '!';
				playerSym = '!';
			default:
				std::cout << "Invalid choice please try again" << std::endl;
			}
		} while (choice != 1 && choice != 2 && choice != 3);
		return playerSym;
	}

	char computer(char playerSym)
	{	
		char computerSym{};
		if (playerSym == 'X')
		{
			computerSym = 'O';
		}
		else if (playerSym == 'O')
		{
			computerSym = 'X';
		}
		return computerSym;
	}

	void displayBoard(char Player, char Computer)
	{
		system("cls");
		std::cout << " -+-+- " << std::endl;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3 ; j++)
			{
				std::cout << "|" << GameBoard[i][j];
			}
			std::cout << "|" << std::endl;
		}
		std::cout << " -+-+- " << std::endl;
	}

	int computerMove(int position, std::vector<int> prevPositions, char Computer)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(0, 2); // Adjusted the range

		int comprow, compcol, comPos;

		bool isValidMove = false;
		do
		{
			comprow = dis(gen);
			compcol = dis(gen);
			comPos = comprow * 10 + compcol;
			isValidMove = (GameBoard[comprow][compcol] == '_'); // Check if the position is empty
		} while (!isValidMove);

		GameBoard[comprow][compcol] = Computer;
		return comPos;
	}



	void PlayerCheckPosition(int position, char Player, std::vector<int> prevPositions)
	{
		bool checkposition = false;

		do
		{
			for (int i = 0; i < prevPositions.size(); i++) {
				if (position != prevPositions[i])
				{
					checkposition = true;
				}
				else {
					coloring::colorText("Invalid input, try again: ","GrayWhite","Red");
					std::cin >> position;
				}
			}
		} while (checkposition == false);
		
		GameBoard[(position / 10) - 1][(position % 10) - 1] = Player;
	}

	char checkWinCon()
	{
		char X = 'X';
		char O = 'O';
		//check diagonals
		if ((GameBoard[0][0]==X) && (GameBoard[1][1] == X) && (GameBoard[2][2] == X))
		{
			return X;
		}else 
		if ((GameBoard[0][0] == O) && (GameBoard[1][1] == O) && (GameBoard[2][2] == O))
		{
			return O;
		}else 
		if ((GameBoard[0][2] == X) && (GameBoard[1][1] == X) && (GameBoard[2][0] == X))
		{
			return X;
		}else
		if ((GameBoard[0][2] == O) && (GameBoard[1][1] == O) && (GameBoard[2][0] == O))
		{
			return O;
		}

		//check rows
		if ((GameBoard[0][0] == X) && (GameBoard[0][1] == X) && (GameBoard[0][2] == X) ||
			(GameBoard[1][0] == X) && (GameBoard[1][1] == X) && (GameBoard[1][2] == X) ||
			(GameBoard[2][0] == X) && (GameBoard[2][1] == X) && (GameBoard[2][2] == X) )
		{
			return X;
		}
		if ((GameBoard[0][0] == O) && (GameBoard[0][1] == O) && (GameBoard[0][2] == O) ||
			(GameBoard[1][0] == O) && (GameBoard[1][1] == O) && (GameBoard[1][2] == O) ||
			(GameBoard[2][0] == O) && (GameBoard[2][1] == O) && (GameBoard[2][2] == O))
		{
			return O;
		}

		//check columns
		if ((GameBoard[0][0] == X) && (GameBoard[1][0] == X) && (GameBoard[2][0] == X) ||
			(GameBoard[0][1] == X) && (GameBoard[1][1] == X) && (GameBoard[2][1] == X) ||
			(GameBoard[0][2] == X) && (GameBoard[1][2] == X) && (GameBoard[2][2] == X))
		{
			return X;
		}
		if ((GameBoard[0][0] == O) && (GameBoard[1][0] == O) && (GameBoard[2][0] == O) ||
			(GameBoard[0][1] == O) && (GameBoard[1][1] == O) && (GameBoard[2][1] == O) ||
			(GameBoard[0][2] == O) && (GameBoard[1][2] == O) && (GameBoard[2][2] == O))
		{
			return O;
		}
		return 0;
	}

	bool checkDrawCon()
	{
		bool boardIsFull = true; 
		
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				
				if (GameBoard[i][j] != 'X' && GameBoard[i][j] != 'O')
				{
					boardIsFull = false;
					break; 
				}
			}
			if (!boardIsFull)
				break; 
		}
		return boardIsFull;
	}

	void gameOn(char Player, char Computer)
	{
		std::vector<int> prevPositions{0}; 
		bool gameState = true;
		int position{ 0 };
		while (gameState)
		{
			int position;
			int compMove;
			std::cin >> position;
				
			Board::PlayerCheckPosition(position, Player, prevPositions);
			Board::displayBoard(Player, Computer);
			prevPositions.push_back(position);
			if (checkWinCon() == 'O' || checkWinCon() == 'X')
			{
				std::cout << checkWinCon() << " has Won the game.";
				break;
			}
			else if (checkDrawCon())
			{
				std::cout << "The game has ended in a draw";
				break;
			}
			compMove=Board::computerMove(position, prevPositions, Computer);			
			Board::displayBoard(Player, Computer);
			prevPositions.push_back(compMove);
			if (checkWinCon() == 'O' || checkWinCon() == 'X')
			{
				std::cout << checkWinCon() << " has Won the game.";
				break;
			}
			else if (checkDrawCon())
			{
				std::cout << "The game has ended in a draw";
				break;
			}
		}
	}
};

int main() 
{
	Board myBoard;
	char Player = myBoard.screenMenu();
	if (Player == '!')
	{
		return 1;
	}

	myBoard.displayBoard(Player, myBoard.computer(Player));
	myBoard.gameOn(Player, myBoard.computer(Player));

	return 0;
}