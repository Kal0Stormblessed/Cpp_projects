#include <iostream>
#include "TestHeader.h"
#include <vector>
#include <random>

//TicTacToe game
/*
Main menu
Select X or O
DisplayBoard
RedX, BlueO
Endscreed(play again, exit)
*/
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

	int computerMove(int position, std::vector<int> prevPositions )
	{

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(1, 3);
		bool checkPlayerMove{ false };
		int comprow, compcol, comPos;

		while (checkPlayerMove == false)
		{
			comprow = dis(gen);
			compcol = dis(gen);
			comPos = comprow * 10 + compcol;
			for (int i = 0; i < prevPositions.size(); i++) {
				if (comPos != prevPositions[i])
				{
					checkPlayerMove = true;
				}
				else {
					break;
				}
			}
			
		}
		std::cout << comPos;
			return comPos;
	}

	void gameOn(char Player, char Computer)
	{
		std::vector<int> prevPositions;
		bool gameState = true;
		int position[2][2];
		while (gameState)
		{
			int position;
			int computerPosition;
			std::cin >> position;
			switch (position)
			{
			case 11:
				GameBoard[(position / 10) - 1][(position % 10) - 1] = Player;
				Board::displayBoard(Player, Computer);
				prevPositions.push_back(position);
				computerPosition = Board::computerMove(position, prevPositions);
				GameBoard[(computerPosition / 10) - 1][(computerPosition % 10) - 1] = Computer;
				Board::displayBoard(computerPosition, Computer);
				break;

			case 12:
				GameBoard[(position / 10) - 1][(position % 10) - 1] = Player;
				Board::displayBoard(Player, Computer);
				prevPositions.push_back(position);
				computerPosition = Board::computerMove(position, prevPositions);
				GameBoard[(computerPosition / 10) - 1][(computerPosition % 10) - 1] = Computer;
				Board::displayBoard(computerPosition, Computer);
				break;

			case 13:
				GameBoard[(position / 10) - 1][(position % 10) - 1] = Player;
				Board::displayBoard(Player, Computer);
				prevPositions.push_back(position);
				computerPosition = Board::computerMove(position, prevPositions);
				GameBoard[(computerPosition / 10) - 1][(computerPosition % 10) - 1] = Computer;
				Board::displayBoard(computerPosition, Computer);
				break;

			case 21:
				GameBoard[(position / 10) - 1][(position % 10) - 1] = Player;
				Board::displayBoard(Player, Computer);
				prevPositions.push_back(position);
				computerPosition = Board::computerMove(position, prevPositions);
				GameBoard[(computerPosition / 10) - 1][(computerPosition % 10) - 1] = Computer;
				Board::displayBoard(computerPosition, Computer);
				break;

			case 22:
				GameBoard[(position / 10) - 1][(position % 10) - 1] = Player;
				Board::displayBoard(Player, Computer);
				prevPositions.push_back(position);
				computerPosition = Board::computerMove(position, prevPositions);
				GameBoard[(computerPosition / 10) - 1][(computerPosition % 10) - 1] = Computer;
				Board::displayBoard(computerPosition, Computer);
				break;

			case 23:
				GameBoard[(position / 10) - 1][(position % 10) - 1] = Player;
				Board::displayBoard(Player, Computer);
				prevPositions.push_back(position);
				computerPosition = Board::computerMove(position, prevPositions);
				GameBoard[(computerPosition / 10) - 1][(computerPosition % 10) - 1] = Computer;
				Board::displayBoard(computerPosition, Computer);
				break;

			case 31:
				GameBoard[(position / 10) - 1][(position % 10) - 1] = Player;
				Board::displayBoard(Player, Computer);
				prevPositions.push_back(position);
				computerPosition = Board::computerMove(position, prevPositions);
				GameBoard[(computerPosition / 10) - 1][(computerPosition % 10) - 1] = Computer;
				Board::displayBoard(computerPosition, Computer);
				break;

			case 32:
				GameBoard[(position / 10) - 1][(position % 10) - 1] = Player;
				Board::displayBoard(Player, Computer);
				prevPositions.push_back(position);
				computerPosition = Board::computerMove(position, prevPositions);
				GameBoard[(computerPosition / 10) - 1][(computerPosition % 10) - 1] = Computer;
				Board::displayBoard(computerPosition, Computer);
				break;

			case 33:
				GameBoard[(position / 10) - 1][(position % 10) - 1] = Player;
				Board::displayBoard(Player, Computer);
				prevPositions.push_back(position);
				computerPosition = Board::computerMove(position, prevPositions);
				GameBoard[(computerPosition / 10) - 1][(computerPosition % 10) - 1] = Computer;
				Board::displayBoard(computerPosition, Computer);
				break;
			default: 
				std::cout << "Invalid input, try again: ";
				break;

			}
		}
	}
};

int main() 
{
	Board myBoard;
	char Player = myBoard.screenMenu();

	myBoard.displayBoard(Player, myBoard.computer(Player));
	myBoard.gameOn(Player, myBoard.computer(Player));
	//coloring::colorText("");
	return 0;
}