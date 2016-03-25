/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include <stdlib.h>

int *spiral_wrapper(int rows, int columns, int **input_array, int rounds, int *ans, int index)
{
	int i;

	for (i = rounds; i < columns - 1 - rounds; i++, index++)
		ans[index] = input_array[rounds][i];
	if (index >= rows*columns)
		return ans;

	for (i = rounds; i < rows - 1  - rounds; i++, index++)
		ans[index] = input_array[i][columns - 1 - rounds];
	if (index >= rows*columns)
		return ans;

	for (i = columns - 1 - rounds; i >= 1 + rounds; i--, index++)
		ans[index] = input_array[rows - 1 - rounds][i];
	if (index >= rows*columns)
		return ans;

	for (i = rows - 1 - rounds; i >= 1 + rounds; i--, index++)
		ans[index] = input_array[i][rounds];
	if (index >= rows*columns)
		return ans;

	rounds++;
	if (index == rows*columns - 1 && rows % 2 == 1 && columns % 2 == 1)
	{
		if (columns - rounds - 1 >= 0)
			ans[index] = input_array[rounds][columns - rounds - 1];
		index++;
		return ans;
	}

	return spiral_wrapper(rows, columns, input_array, rounds, ans, index);
}

int *spiral(int rows, int columns, int **input_array)
{
	if (rows <= 0 || columns <= 0 || input_array == NULL)
		return NULL;

	int *ans = (int*)calloc(rows*columns, sizeof(int));
	if (rows == 1 && columns == 1)
	{
		ans[0] = input_array[0][0];
		return ans;
	}
	return spiral_wrapper(rows, columns, input_array, 0, ans, 0);
}
