#include <iostream>
#include "ReExMa.h"

bool Solution::isMatch(std::string s, std::string p)
{
	int m = s.length(), n = p.length();
	std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));
	dp[0][0] = true;

	//preprocess simple parrterns like a* a*b* etc
	for (int j = 1; j <= n; j++) {
		if (p[j - 1] == '*') {
			dp[0][j] = dp[0][j - 2];
		}
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else if (p[j - 1] == '*') {
				dp[i][j] = dp[i][j - 2] ||
					(dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
			}
		}
	}

	std::cout << dp[m][n] <<std::endl;

	return dp[m][n];
}
