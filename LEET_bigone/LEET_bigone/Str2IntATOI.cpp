#include <iostream>
#include "Str2IntATOI.h"

int Solution::myAtoi(std::string s)
{
	int result = 0;
	bool negative{ false }, started{ false };

	for (char c : s) {
		if (c == ' ' && !started)
		continue;
		if (c == '+' && !started) {
			started = true;
			continue;
		}
		if (c == '-' && !started) {
			negative = true;
			started = true;
			continue;
		}
		if ( c >='0' && c<='9') {
			started = true;
			int digit = c - '0';
			if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
				return negative ? INT_MIN : INT_MAX;	
			}
			result = result * 10 + digit;
		}
		else {
			break;
		}
	}
	return negative ? -result : result;
}
