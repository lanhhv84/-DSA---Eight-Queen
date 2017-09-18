#include <iostream>
#include <stack>

using namespace std;

void printBoard();
void generateBoard(int);
bool isSafe(int row, int col);
bool putQueen(int row);
void eightQueen();

stack<stack<int>> traceAll;
char** board = nullptr;
int* track = nullptr;
int boardSize = 0;


int main()
{
	generateBoard(9);
	printBoard();
	eightQueen();
	
	return false;
}

void printBoard()
{
	cout << endl;
	for (int i = 0; i < boardSize; ++i)
	{
		for (int j = 0; j < boardSize; ++j)
			cout << board[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}
void generateBoard(int size)
{
	boardSize = size;
	board = new char*[boardSize];
	for (int i = 0; i < boardSize; ++i)
		board[i] = new char[boardSize];
	for (int i = 0; i < boardSize; ++i)
		for (int j = 0; j < boardSize; ++j)
			board[i][j] = '-';
	track = new int[boardSize];
	for (int i = 0; i < boardSize; ++i)
		track[i] = 0;

}
bool isSafe(int row, int col)
{
	for (int i = 0; i < boardSize; ++i)
	{
		// Check column
		if (i != col)
			if (board[row][i] == '*')
				return false;
		// Check row
		if (i != row)
			if (board[i][col] == '*')
				return false;
		// Check hori
		for (int j = 0; j < boardSize; ++j)
		{
			if (i != col && j != row)
			{
				if ((i + j) == (col + row) || (i - j) == (col - row))
					if (board[j][i] == '*')
						return false;
			}
		}
	}
	return true;
}
bool putQueen(int row)
{
	bool found = false;		// Flag variable, if put queen in row "row" successful, this will be assigned to true
	int flag = -1;			// Index of column will put queen
	for (int i = track[row]; i < boardSize; ++i)	// Traverse all column of row "row"
	{
		if (isSafe(row, i))		// If can put queen in board[row][i]
		{
			found = true;		// Assigned flag to true 
			flag = i;			// Store position to put queen
			track[row] = i + 1;		// Track 
			break;
		}
	}

	if (found)
	{
		board[row][flag] = '*';
		if (row < boardSize - 1)
			return putQueen(row + 1);
		else if ( row == boardSize - 1)
			return true;
	}
	else
	{
		if (row == 0)
			return false;
		board[row - 1][track[row - 1] - 1] = '-';
		track[row] = 0;
		return putQueen(row - 1);
	}
}
void eightQueen()
{
	bool solve = putQueen(0);
	int count = 0;
	while (solve)
	{
		cout << "Cach so " << ++count << endl;
		printBoard();
		stack<int> trace;
		for (int i = boardSize - 1; i > -1; --i)
		{
			for (int j = 0; j < boardSize; ++j)
				if (board[i][j] == '*')
					trace.push(j);
		}
		traceAll.push(trace);
		board[boardSize - 1][track[boardSize - 1] - 1] = '-';
		solve = putQueen(boardSize - 1);
	}
}