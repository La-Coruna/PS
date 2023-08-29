#include <iostream>
#include <vector>

// best
int combination(int n, int k) {
    std::vector<int> dp(k + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = std::min(i, k); j > 0; --j) {
            dp[j] += dp[j - 1];
        }
    }

    return dp[k];
}

// use dynamic programming
int combination(int n, int k) {
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, 0));

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= std::min(i, k); ++j) {
            if (j == 0 || j == i) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }

    return dp[n][k];
}

// simple version
int combination(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    } else {
        return combination(n - 1, k - 1) + combination(n - 1, k);
    }
}