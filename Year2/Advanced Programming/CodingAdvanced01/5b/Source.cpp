#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

typedef vector<vector<int>> matrix;
int n;

//point on the board
struct point
{
	// 'x' and 'y' coordinates
	int y, x;
};

// displays the knight tour solution
void printTour(matrix& chessboard)
{
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(2) << chessboard[i][j] << " ";
		}
		cout << endl;
	}
}

// is next move possible
bool isMovePossible(const point& next_move, matrix& chessboard)
{
	const int x = next_move.x;
	const int y = next_move.y;

	if ((x >= 0 && x < n) && (y >= 0 && y < n) && (chessboard[y][x] == 0))
	{
		return true;
	}

	return false;
}


/**
* \brief recursive function to find a knight tour
* \param chessboard
* \param possible_moves
* \param current
* \param move_count current moves
* \return
*/
bool findTour(matrix& chessboard, vector<point>& possible_moves,
	const point& current, const int move_count)
{
	point next_move;
	if (move_count == n * n)
	{
		// Knight tour is completed i.e all cells on the
		// chess board has been visited by knight once 
		return true;
	}

	// try out the possible moves starting from the current coordinate
	for (int i = 0; i < possible_moves.size(); i++)
	{
		// get the next move
		next_move.y = current.y + possible_moves[i].y;
		next_move.x = current.x + possible_moves[i].x;

		if (isMovePossible(next_move, chessboard))
		{
			// if the move is possible
			// increment the move count and store it in tour matrix
			chessboard[next_move.y][next_move.x] = move_count + 1;
			if (findTour(chessboard, possible_moves, next_move, move_count + 1) == true)
			{
				return true;
			}
			else
			{
				// this move was invalid, try out other possiblities 
				chessboard[next_move.y][next_move.x] = 0;
			}
		}
	}
	return false;
}


void printZero()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << "0" << " ";
		}
		cout << endl;
	}
}

void knightTour(int x, int y)
{
	matrix chessboard;

	for (int i = 0; i < n; ++i)
	{
		vector<int> row(n);
		chessboard.push_back(row);
	}

	// all possible moves that knight can take
	vector<point> possible_moves =
	{
		{ 1,2 },
		{ 1,-2 },
		{ 2,1 },
		{ 2,-1 },
		{ -1,-2 },
		{ -2,-1 },
		{ -2,1 },
		{ -1,2 }
	};

	// knight tour starts from coordinate (0,0)
	const point starting_point = { y,x };
	chessboard[y][x] = 1;

	// find a possible knight tour using a recursive function
	// starting from current move 
	if (findTour(chessboard, possible_moves, starting_point, 1) == false)
	{
		//		cout << "\nKnight tour does not exist";
		printZero();
	}
	else
	{
		//		cout << "\nTour exist ...\n";
		printTour(chessboard);
	}
}

// main
int main()
{
	int x, y;

	while (cin >> n >> x >> y)
	{
		x--;
		y--;
		//const clock_t begin = clock();

		knightTour(x, y);
		//const clock_t end = clock();

		//cout << "time elapsed: " << double(end - begin) / CLOCKS_PER_SEC << endl;
		cout << endl;
	}

	return 0;
}
