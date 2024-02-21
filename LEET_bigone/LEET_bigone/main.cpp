#include <iostream>
#include "ContainerWithMostWater.h"
#include <vector>
int main()
{
	Solution solution;

	std::vector<int> height1 = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	std::vector<int> height2 = { 1, 1 };

	solution.maxArea(height1);
	solution.maxArea(height2);

	return 0;
}

