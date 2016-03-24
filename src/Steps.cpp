/*

	You have N steps to climb .
	You can either take one step or two steps at a time .
	You need to find the total number of ways you can reach N steps .

	Example : For N=4 , You can either reach 4 steps in following ways
	->1111
	->112
	->121
	->211
	->22
	So total number of ways is 5

	Input : A Integer denoting N (number of steps )
	Output : Return an Integer denoting the number of ways to reach N steps

	Example Input : get_steps(5)
	Example Output : Returns 8

	Note : Test Cases would be small <25.

*/
#include "stdafx.h"


int factorial(int N)
{
	if (N == 1 || N == 0)
		return 1;
	else
		return N * factorial(N - 1);
}

int num_of_permutations(int ones, int twos)
{
	return factorial(ones + twos) / (factorial(ones)*factorial(twos));
}

int get_steps_recur(int ones, int twos)
{
	if (ones == 1)
		return ones + twos;
	if (ones == 0)
		return 1;
	return num_of_permutations(ones, twos) + get_steps_recur(ones - 2, twos + 1);
}

int get_steps(int s)
{
	return get_steps_recur(s, 0);
}
