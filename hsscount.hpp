// hsscount.hpp
// Jenae Matson
// 2023-10-10
// Header for Assignment 4 functions

#pragma once
#include <vector>

// hssCount
// Defined in source file
int hssCount(int dim_x, int dim_y,
			int hole_x, int hole_y,
			int start_x, int start_y,
			int finish_x, int finish_y);

// hssCount_recurse
// Defined in source file
int hssCount_recurse(std::vector<std::vector<int>> & board,
					int dim_x, int dim_y,
					int finish_x, int finish_y,
					int curr_x, int curr_y,
					int squaresLeft);
