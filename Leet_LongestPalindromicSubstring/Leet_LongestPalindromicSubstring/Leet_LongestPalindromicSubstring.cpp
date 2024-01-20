#include <iostream>
#include <string>

class Solution {
public:
    std::string longestPalindrome(const std::string& s) {
        std::size_t length = s.length();

        if (length <= 1) {
            return s;
        }

        std::size_t start = 0;
        std::size_t maxLength = 1;

        for (std::size_t i = 1; i < length; ++i) {
            // Check even-length palindrome centered at i
            std::size_t leftEven = i - 1;
            std::size_t rightEven = i;

            // Check odd-length palindrome centered at i
            std::size_t leftOdd = i - 1;
            std::size_t rightOdd = i + 1;

            // Check even-length palindrome
            while (leftEven < length && rightEven < length && s[leftEven] == s[rightEven]) {
                if (rightEven - leftEven + 1 > maxLength) {
                    start = leftEven;
                    maxLength = rightEven - leftEven + 1;
                }
                ++rightEven;
                --leftEven;
            }

            // Check odd-length palindrome
            while (leftOdd < length && rightOdd < length && s[leftOdd] == s[rightOdd]) {
                if (rightOdd - leftOdd + 1 > maxLength) {
                    start = leftOdd;
                    maxLength = rightOdd - leftOdd + 1;
                }
                ++rightOdd;
                --leftOdd;
            }
        }

        return s.substr(start, maxLength);
    }
};

int main() {
    Solution solution;

    std::string result1 = solution.longestPalindrome("babad");
    std::cout << "Longest Palindrome 1: " << result1 << std::endl;

    std::string result2 = solution.longestPalindrome("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz....");
    std::cout << "Longest Palindrome 2: " << result2 << std::endl;

    return 0;
}
