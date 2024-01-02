// Leet_twoSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>


class Solution {
private:
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::cout << "Enter the numbers for nums: \n";
        int num;
        while (std::cin >> num && num !='/') {
            nums.push_back(num);
        }

        if (nums.empty()) {
            std::cerr << "Vector is empty, cannot perform task." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
        }

        return std::vector<int>();
    };

};

int main()
{
    std::cout << "Hello World!\n";
}
