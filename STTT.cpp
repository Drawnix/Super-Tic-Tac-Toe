#include <iostream>
#include <string>

using namespace std;

class GreatBoard
{
private:
	string position[10][10];
	int quads[4][4];
	int player = 1;

public:
	GreatBoard();
	string getPlayer(int p);
	void ClearGrid();
	void DrawGrid();
	void ChooseQuadrant(int x, int y);
	void ChooseNewQuadrant();
	void AskPosition(int xTop, int xBot, int yTop, int yBot);
	void Turn(int X, int Y);
	void checkLocalWinner();
	void winQuadrant(int x, int y);
};

GreatBoard::GreatBoard()
{

}

string GreatBoard::getPlayer(int p)
{
	if (p == 1) { return "X"; }
	if (p == 2) { return "O"; }
}

void GreatBoard::ClearGrid()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			position[i][j] = " ";
		}
	}
	for (int x = 1; x <= 3; x++)
	{
		for (int y = 1; y <= 3; y++)
		{
			quads[x][y] = 0;
		}
	}
}

void GreatBoard::DrawGrid()
{	
	system("cls");
	cout << "\t\t\t\t\t____________Super_Tix_Tac_Toe____________\n";
	cout << "\t\t\t\t\t_______________by_Drawnix________________\n\n\n";

	cout << "\t\t\t\t\t/---------------------------------------/\n";
	for (int i = 1; i <= 9; i++)
	{ 
		if (i == 4 or i == 7)
		{
			cout << "\t\t\t\t\t||";
			for (int j = 1; j <= 9; j++)
			{
				if (j == 3 or j == 6)
				{
					cout << "---||";
				}
				else
				{
					cout << "----";
				}
			}
			cout << "|\n\t\t\t\t\t||";
		}
		else
		{
			cout << "\t\t\t\t\t||";
			for (int j = 1; j <= 9; j++)
			{
				if (j == 3 or j == 6)
				{
					cout << "---||";
				}
				else
				{
					cout << "---|";
				}
			}
			cout << "|\n\t\t\t\t\t||";
		}
		
		
		for (int j = 1; j <= 9; j++)
		{
			if (j == 3 or j == 6)
			{
				cout << " " << position[i][j] << " ||";
			}
			else
			{
				cout << " " << position[i][j] << " |";
			}
		}
		cout << "|\n";
		
	}
	cout << "\t\t\t\t\t||---|---|---||---|---|---||---|---|---||\n"<<
			"\t\t\t\t\t/---------------------------------------/\n";
}

void GreatBoard::ChooseQuadrant(int x, int y)
{
	int xTop, xBot, yTop, yBot;
	if (quads[x][y] == 0)
	{
		if (x == 1)
		{
			xBot = 1;
			xTop = 3;
		}
		else if (x == 2)
		{
			xBot = 4;
			xTop = 6;
		}
		else if (x == 3)
		{
			xBot = 7;
			xTop = 9;
		}
		if (y == 1)
		{
			yBot = 1;
			yTop = 3;
		}
		else if (y == 2)
		{
			yBot = 4;
			yTop = 6;
		}
		else if (y == 3)
		{
			yBot = 7;
			yTop = 9;
		}
		AskPosition(xTop, xBot, yTop, yBot);
	}
	else
	{
		ChooseNewQuadrant();
	}
}

void GreatBoard::ChooseNewQuadrant()
{
	int x, y;
	cout << "\n Choose a new Quadrant to play (Player " << player << " [" << getPlayer(player) << "]): \n";
	do
	{
		cout << "QUADRANT - (play between 1 and 3) - X: "; cin >> x;
		while (x < 1 or x > 3)
		{
			cout << "Not allowed. Try again (play between 1 and 3) - X: "; cin >> x;
		}
		cout << "QUADRANT - (play between 1 and 3) - Y: "; cin >> y;
		while (y < 1 or y > 3)
		{
			cout << "Not allowed. Try again (play between 1 and 3) - Y: "; cin >> y;
		}
	} while (quads[x][y] != 0);
	
	DrawGrid();
	ChooseQuadrant(x, y);
}

void GreatBoard::AskPosition(int xTop, int xBot, int yTop, int yBot)
{
	int x, y;
	cout << "\n Choose a new Position to play (Player " << player << " [" << getPlayer(player) << "]): \n";
	do
	{
		cout << "POSITION - (play between " << xBot << " and " << xTop << ") - X: "; cin >> x;
		while (x < xBot or x > xTop)
		{
			cout << "Not allowed. Try again (play between " << xBot << " and " << xTop <<") - X: "; cin >> x;
		}
		cout << "POSITION - (play between " << yBot << " and " << yTop << ") - Y: "; cin >> y;
		while (y < yBot or y > yTop)
		{
			cout << "Not allowed. Try again (play between " << yBot << " and " << yTop << ") - Y: "; cin >> y;
		}
	} while (position[x][y] != " ");
	Turn(x, y);

	
}

void GreatBoard::Turn(int X, int Y)
{
	int xQuad, yQuad;
	if (player == 1)
	{
		position[X][Y] = "X";
		checkLocalWinner();
		player = 2;
	}
	else if (player == 2)
	{
		position[X][Y] = "O";
		checkLocalWinner();
		player = 1;
	}


	if (X == 1 or X == 4 or X == 7)
	{
		xQuad = 1;
	}
	else if (X == 2 or X == 5 or X == 8)
	{
		xQuad = 2;
	}
	else if (X == 3 or X == 6 or X == 9)
	{
		xQuad = 3;
	}
	if (Y == 1 or Y == 4 or Y == 7)
	{
		yQuad = 1;
	}
	else if (Y == 2 or Y == 5 or Y == 8)
	{
		yQuad = 2;
	}
	else if (Y == 3 or Y == 6 or Y == 9)
	{
		yQuad = 3;
	}

	DrawGrid();
	
	ChooseQuadrant(xQuad, yQuad);
}

void GreatBoard::checkLocalWinner()
{
	int qx = 0;
	int qy = 0;
	for (int i = 0; i <= 6; i += 3)
	{
		qx++;
		for (int j = 0; j <= 6; j += 3)
		{
			qy++;
			for (int x = 1; x <= 3; x++)
			{
				if (quads[qx][qy] == 0)
				{
					if ((position[x+i][1+j] == position[x+i][2+j] and position[x+i][1+j] == position[x+i][3+j] and position[x+i][1+j] != " ") or
						(position[1+i][x+j] == position[2+i][x+j] and position[1+i][x+j] == position[3+i][x+j] and position[1+i][x+j] != " ") or
						(position[1+i][1+j] == position[2+i][2+j] and position[1+i][1+j] == position[3+i][3+j] and position[2+i][2+j] != " ") or
						(position[1+i][3+j] == position[2+i][2+j] and position[1+i][3+j] == position[3+i][1+j] and position[2+i][2+j] != " "))
					{
						quads[qx][qy] = player;
						winQuadrant(i, j);
					}
				}
				
			}
		}
	}
	

}

void GreatBoard::winQuadrant(int x, int y)
{
	position[1 + x][1 + y] = getPlayer(player);position[1 + x][2 + y] = getPlayer(player);position[1 + x][3 + y] = getPlayer(player);
	position[2 + x][1 + y] = getPlayer(player);position[2 + x][2 + y] = getPlayer(player);position[2 + x][3 + y] = getPlayer(player);
	position[3 + x][1 + y] = getPlayer(player);position[3 + x][2 + y] = getPlayer(player);position[3 + x][3 + y] = getPlayer(player);
	DrawGrid();
	if (player == 1)
	{
		player = 2;
	}
	else if (player == 2)
	{
		player = 1;
	}
	ChooseNewQuadrant();
}


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
			
			cout << "Winner: Player " << player << endl;
			if (actualPlayer == 1)
			{
				FCounter++;
			}
			else if (actualPlayer == 2)
			{
				SCounter++;
			}
			gameOver = true;
		}
		else if (position[1][1] != " " and position[1][2] != " " and position[1][3] != " "
			and position[2][1] != " " and position[2][2] != " " and position[2][3] != " "
			and position[3][1] != " " and position[3][2] != " " and position[3][3] != " ")
		{
			cout << "Match!";
			gameOver = true;
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

void MainMenu()
{
	int a;
	int selector;
	system("cls");
	cout << "\t\t\t\t\t____________Super_Tix_Tac_Toe____________\n";
	cout << "\t\t\t\t\t_______________by_Drawnix________________\n\n\n";
	cout << "Main Menu:\n\t1_ Normal tic tic toe\n\t2_ Super tic tac toe\n\t3_ Rules\n\t4_ Quit\n";
	cin >> selector;
	while ((selector < 1 or selector > 4) and selector != 69)
	{
		cout << "Not found, yet :). Try again with the specified options: "; cin >> selector;
	}
	if (selector == 1)
	{
		char newGame;
		SmallBoard one;

		do
		{
			one.GameCycle();
			cout << "Do you want to play again? (y/n): "; cin >> newGame;
		} while (newGame == 'y');
		MainMenu();
	}
	else if (selector == 2)
	{
		GreatBoard two;
		two.ClearGrid();
		two.DrawGrid();
		two.ChooseNewQuadrant();
	}
	else if (selector == 3)
	{
		
		system("cls");
		cout << "placeholder for game rules";
		cin >> a;
		MainMenu();
	}
	else if (selector == 4)
	{
		exit(0);
	}
	else if (selector == 69)
	{
		system("cls");
		cout << "Really... what were you expecting to find here? Are you dumb?";
		cin >> a;
		MainMenu();
	}
}

int main()
{
	MainMenu();
	return 0;
}