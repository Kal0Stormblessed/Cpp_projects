#include "Palindrome.h"
#include <iostream>

bool Solution::isPalindrome(int x) {
	bool negative = false;
	int aux1, aux2{ 0 };
	aux1 = x;
	
	if (x < 0) {
		negative = true;
	}
	do {
		aux2 = aux2 * 10 + aux1 % 10;
		aux1 = aux1 / 10;	
	} while (aux1 != 0);
	if (negative == false && x == aux2) {
		return true;
	}
	else if (negative == true && x == aux2) {
		return false;
	}
	else {
		return false;
	}

	return false;
}
