#include <iostream>

using namespace std;

class SmallBoard
{
private:
	string position[4][4];
	bool gameOver;
	int actualPlayer;
	int FCounter, SCounter;

public:
	SmallBoard();
	void ClearGrid();
	void DrawGrid();
	void AskPosition(int player);
	void GameCycle();
	void checkWinner(int player);
	void Turn(int X, int Y, int player);
};

SmallBoard::SmallBoard() 
{
	gameOver = false;
	actualPlayer = 1;
	FCounter = 0;
	SCounter = 0;
}

void SmallBoard::ClearGrid()
{
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			position[i][j] = " ";
		}
	}
}

void SmallBoard::DrawGrid()
{
	system("cls");
	cout << "\t\t\t\t\t_________TIC_TAC_TOE_________"<<endl<<endl;
	cout << "Now playing: Player " << actualPlayer << endl;
	cout << "\t\t\t\t\t\t\t\t\t\tWins:\n\t\t\t\t\t\t\t\t\t\t\tPlayer 1: " << FCounter << "\n\t\t\t\t\t\t\t\t\t\t\tPlayer 2: " << SCounter<<endl;
	cout <<
		"\t\t\t\t\t\t|---|---|---|" << endl << "\t\t\t\t\t\t| " << position[1][1] << " | " << position[1][2] << " | " << position[1][3] << " |" << endl <<
		"\t\t\t\t\t\t|---|---|---|" << endl << "\t\t\t\t\t\t| " << position[2][1] << " | " << position[2][2] << " | " << position[2][3] << " |" << endl <<
		"\t\t\t\t\t\t|---|---|---|" << endl << "\t\t\t\t\t\t| " << position[3][1] << " | " << position[3][2] << " | " << position[3][3] << " |" << endl <<
		"\t\t\t\t\t\t|---|---|---|" << endl;
}

void SmallBoard::AskPosition(int player)
{
	int x, y;
	do
	{
		cout << "X: "; cin >> x;
		while (x < 1 or x > 3)
		{
			cout << "Not allowed. Try again: "; cin >> x;
		}
		cout << "Y: "; cin >> y;
		while (y < 1 or y > 3)
		{
			cout << "Not allowed. Try again: "; cin >> y;
		}
	} while (position[x][y] != " ");
	Turn(x, y, player);
}

void SmallBoard::GameCycle()
{
	gameOver = false;
	ClearGrid();
	DrawGrid();
	while (!gameOver)
	{
		for (int i = 1; i <= 2; i++)
		{
			actualPlayer = i;
			DrawGrid();
			AskPosition(i);
			if (gameOver)
			{
				break;
			}
		}
		
	}
	if (actualPlayer == 1)
	{
		FCounter++;
	}
	else if (actualPlayer == 2)
	{
		SCounter++;
	}
	DrawGrid();
}

void SmallBoard::checkWinner(int player)
{
	for (int x = 1; x <= 3; x++)
	{
		if ((position[x][1] == position[x][2] and position[x][1] == position[x][3] and position[x][1] != " ") or 
			(position[1][x] == position[2][x] and position[1][x] == position[3][x] and position[1][x] != " ") or
			(position[1][1] == position[2][2] and position[1][1] == position[3][3] and position[2][2] != " ") or
			(position[1][3] == position[2][2] and position[1][3] == position[3][1] and position[2][2] != " "))
		{
			gameOver = true;
			cout << "Winner: Player " << player << endl;
		}
	}
	
	
}

void SmallBoard::Turn(int X, int Y, int player)
{
	if (player == 1)
	{
		position[X][Y] = "X";
	}
	else if (player == 2)
	{
		position[X][Y] = "O";
	}

	DrawGrid();
	checkWinner(player);
}


int main()
{
	char newGame;
	SmallBoard one;
		
	do
	{
		one.GameCycle();
		cout << "Do you want to play again? (y/n): "; cin >> newGame;
	} while (newGame == 'y');
	
	
	return 0;
}