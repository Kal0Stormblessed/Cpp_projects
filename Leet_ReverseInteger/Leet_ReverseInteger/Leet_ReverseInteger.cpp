#include <iostream>
#include <vector>
#include <limits>

class Solution {
public:
    int reverse(int64_t x) {
        int64_t aux = 0;
        int sign = (x < 0) ? -1 : 1;  // Store the sign of the original number

        x = std::abs(x);  // Work with the absolute value for reversal

        while (x != 0) {
            aux = aux * 10 + x % 10;
            x = x / 10;
        }

        aux *= sign;  // Apply the sign to the reversed value

        if (aux > std::numeric_limits<int32_t>::max() || aux < std::numeric_limits<int32_t>::min()) {
            std::cout << "Number out of bounds" << std::endl;
            return 0;
        }

        return static_cast<int>(aux);
    }
};

int main()
{
    Solution solution;

    std::cout << solution.reverse(123) << std::endl;
    std::cout <<  solution.reverse(-123) << std::endl;
    std::cout <<  solution.reverse(320) << std::endl;

}

