#include <iostream>
#include "ContainerWithMostWater.h"
#include <algorithm>

int Solution::maxArea(std::vector<int>& height)
{
	int maxArea = 0;
	int left = 0;
	int right = height.size() - 1;

	while (left < right)
	{
		int h = std::min(height[left], height[right]);
		int area = h * (right - left);
		maxArea = std::max(maxArea, area);
		if (height[left] < height[right])
		{
			left++;
		}
		else
		{
			right--;
		}
	}
	return maxArea;
}
