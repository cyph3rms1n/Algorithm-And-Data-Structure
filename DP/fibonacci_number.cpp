// Leetcode : 509. Fibonacci Number
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach 1:
// TC: o(2^n)  SC: o(n)
class Solution {
public:
    int solveDp(int n, vector<int>& dp) {
        if (n <= 1)
            return n;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = solveDp(n - 1, dp) + solveDp(n - 2, dp);
    }
    int fib(int n) {
        if (n <= 1)
            return n;
        vector<int> dp(n + 1, -1);

        return solveDp(n, dp);
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach 2:
// TC: o(n)  SC: o(n)

class Solution {
public:
    int fib(int n) {
        if (n <= 1)
            return n;

        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach 3:
// TC: o(n)  SC: o(1)

class Solution {
public:
    int fib(int n) {
        if (n <= 1)
            return n;

        int a = 0, b = 1;
        int c;

        for (int i = 1; i < n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////
