#include "Palindrome.h"
#include <iostream>

bool Solution::isPalindrome(int x) {
    if (x < 0){ 
        return false;
    }
    long long reversed = 0;
    long long original = x;
    while (x > 0) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    return reversed == original;
}
