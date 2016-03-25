/*
Find if there is a connecting path between two given points in the maze.
The maze is a matrix of order MxN, check if there exists a path between (x1,y1) and (x2,y2).
Two points are said to connected if there is a series of 1's non-diagonally.
Example:
Maze of order 4x4:

1	0	1	0
1	1	0	0
0	1	0	1
0	1	1	1

(x1,y1):(0,0)
(x2,y2):(2,3)

In this case, there exists a connected path:
1
1	1
	1		1
	1	1	1

Since there is a connected path, your function has to return 1.
If a path doesn't exist between two co-ordinates then return 0.
If the co-ordinates are invalid or size of the matrix is invalid then return 0.

Function Prototype :path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2) ;
Maze: Pointer to first element of an array .
rows : No of rows
columns : Columns
x1,x2,y1,y2: Co-ordinates

Hint : You can use path_exists as a wrapper function for your original recursive function which might take
more parameters .
*/

#include<stdlib.h>


int path_exists_wrapper(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	int up, down, left, right, middle, boundary, found = 0;

	middle = x1*columns + y1;
	up = (x1 - 1)*columns + y1;
	down = (x1 + 1)*columns + y1;
	left = x1*columns + (y1 - 1);
	right = x1*columns + (y1 + 1);

	maze[middle] = -1;

	if (x1 == x2 && y1 == y2)
		return 1;

	// Moving Up
	if ((x1 - 1) >= 0)
	{
		if (maze[up] == 1)
			found = path_exists_wrapper(maze, rows, columns, x1 - 1, y1, x2, y2);
		if (found != 0)
			return 1;
	}

	// Moving Down
	if ((x1 + 1) < rows)
	{
		if (maze[down] == 1)
			found = path_exists_wrapper(maze, rows, columns, x1 + 1, y1, x2, y2);
		if (found != 0)
			return 1;
	}

	// Moving Left
	if ((y1 - 1) >= 0)
	{
		if (maze[left] == 1)
			found = path_exists_wrapper(maze, rows, columns, x1, y1 - 1, x2, y2);
		if (found != 0)
			return 1;
	}

	// Moving Right
	if ((y1 + 1) < columns)
	{
		if (maze[right] == 1)
			found = path_exists_wrapper(maze, rows, columns, x1, y1 + 1, x2, y2);
		if (found != 0)
			return 1;
	}

	return 0;
}

int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	int i, k;
	if (rows <= 0 || columns <= 0)
		return 0;
	if (x1 < 0 || x1 > rows)
		return 0;
	if (y1 < 0 || y2 > columns)
		return 0;
	k = path_exists_wrapper(maze, rows, columns, x1, y1, x2, y2);
	
	for (i = 0; i < rows*columns; i++)
		if (maze[i] == -1)
			maze[i] = 1;

	return k;
}
