// hsscount.cpp
// Jenae Matson
// 2023-10-10
// Source for Assignment 4 functions

#include "hsscount.hpp"
#include <vector>
using std::vector;


// hssCount
// Count solutions to a holey-spider-scuttle board given by dimensions and 
// coordinates for the start, end, and hole spots. 
// Pre: dim_x > 0, dim_y > 0
//		0 <= hole_x < dim_x, 0 <= hole_y < dim_y
//		0 <= start_x < dim_x, 0 <= start_y < dim_y
//		0 <= finish_x < dim_x, 0 <= finish_y < dim_y
// Does not throw
int hssCount(int dim_x, int dim_y,
	int hole_x, int hole_y,
	int start_x, int start_y,
	int finish_x, int finish_y)
{
	// Create board
	vector<vector<int>> board(dim_x, vector<int> (dim_y, 0));
	// Set hole and start to visited
	board[hole_x][hole_y] = 1;
	board[start_x][start_y] = 1;

	int squaresLeft = (dim_x * dim_y) - 2;
	return hssCount_recurse(board, dim_x, dim_y, finish_x, finish_y, start_x, start_y, squaresLeft);
}

// hssCount_recurse
// Given a partial solution to a holey-spider-scuttle board, return number of
// full solutions branching from the given path.
// Recursive
// Pre: dim_x > 0, dim_y > 0
//		0 <= finish_x < dim_x, 0 <= finish_y < dim_y
//		0 <= curr_x < dim_x, 0 <= curr_y < dim_y
//		squaresLeft >= 0
// Does not throw
int hssCount_recurse(vector<vector<int>> & board,
					int dim_x, int dim_y,
					int finish_x, int finish_y,
					int curr_x, int curr_y,
					int squaresLeft)
{
	// BASE CASE - full solution
	// All squares have been visited, ending on the finish square
	if (squaresLeft == 0
		&& curr_x == finish_x && curr_y == finish_y)
		return 1;

	// DEAD END
	// If the finish square is reached before all the others have been, a full solution cannot be reached
	if (squaresLeft != 0 && curr_x == finish_x && curr_y == finish_y)
		return 0;

	// RECURSIVE CASE
	int total = 0;
	// Try each of the 8 surrounding squares
	for (int i = -1; i < 2; ++i)
	{
		for (int j = -1; j < 2; ++j)
		{
			// Check if proposed square is on the board and is unvisited
			if (curr_x + i >= 0 && curr_x + i < dim_x
				&& curr_y + j >= 0 && curr_y + j < dim_y
				&& board[curr_x + i][curr_y + j] == 0)
			{
				// Set current location to new square
				curr_x += i;
				curr_y += j;
				// Set square to visited
				board[curr_x][curr_y] = 1;
				// Decrement squaresLeft
				squaresLeft -= 1;
				// Recurse
				total += hssCount_recurse(board, dim_x, dim_y, finish_x, finish_y,
					curr_x, curr_y, squaresLeft);

				// Reset conditions to previous square
				board[curr_x][curr_y] = 0;
				squaresLeft += 1;
				curr_x -= i;
				curr_y -= j;
			}
		}
	}

	return total;
}


