// Leet_twoSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>


class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::vector<int> results;
        std::cout << "Enter the numbers for nums: \n";
        int num;
        std::unordered_map<int, int> hashTable;

        // input loop
        while (std::cin >> num && num != '/') {
            nums.push_back(num);
        }

        // setup for error(empty vector)
        if (nums.empty()) {
            std::cerr << "Vector is empty, cannot perform task." << std::endl;
            std::cin.clear(); // clear err from cin
            std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');// ignore all inputs remained in cin
        }


        //for loop to check the values in vector for sum = target
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            auto it = hashTable.find(complement);

                if (it != hashTable.end())
                {
                    results.push_back(it->second);
                    results.push_back(i);
                }
                hashTable[nums[i]] = i;
        }

        //print result indices
        for (int index : results) {
            std::cout << "[" << index << "]" << ", Value:" << nums[index] << std::endl;
        }

        return results;
    };

};

int main()
{
    Solution solution;
    std::vector<int> nums;

    int target;
    std::cout << "Enter target value: ";
    std::cin >> target;

    std::vector<int> result = solution.twoSum(nums, target);
}
