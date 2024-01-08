#include <iostream>
#include <unordered_set>
#include <algorithm>


class Solution {
public:
	int lengthOfLongestSubstring(std::string s) {
		int n = s.length();
	
		if (n == 0) {
			return 0;
		}
		
		int left{ 0 }, right{ 0 }, maxLength{ 0 };
		std::unordered_set<char> charSet;

		while (right < n) {
			// If the character at the right pointer is not in the set
			// add it to the set and move the right pointer to the right

			if (charSet.find(s[right]) == charSet.end()) {
				charSet.insert(s[right]);
				maxLength = std::max(maxLength, right - left + 1);
				right++;
			}
			else {
				// If the character is in the set, remove the leftmost character
				// from the set and move the left pointer to the right
				charSet.erase(s[left]);
				left++;
			}
		}

		return maxLength;

	}
};



int main()
{
	Solution solution;
	std::cout << solution.lengthOfLongestSubstring("abcabcbb") << std::endl;
	std::cout << solution.lengthOfLongestSubstring("bbbbb") << std::endl;
	std::cout << solution.lengthOfLongestSubstring("pwwkew") << std::endl;


	return 0;
}

