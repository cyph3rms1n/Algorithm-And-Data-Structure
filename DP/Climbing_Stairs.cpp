// LC: 70. Climbing Stairs
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach 1: Brute Force
// TC: o(2^n) SC:o(1)
class Solution {
public:
    int climbStairs(int n) {
        if (n < 0)
            return 0;
        if (n == 0)
            return 1;

        int one_step = climbStairs(n - 1);
        int two_step = climbStairs(n - 2);

        return one_step + two_step;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach 2: Memorization Of Brute Force
// TC: o(n) SC:o(n)
class Solution {
public:
    int t[46];

    int solve(int n) {
        if (n < 0)
            return 0;
        if (n == 0)
            return 1;
        if (t[n] != -1)
            return t[n];
        int one_step = solve(n - 1);
        int two_step = solve(n - 2);
        return t[n] = one_step + two_step;
    }
    int climbStairs(int n) {
        memset(t, -1, sizeof(t));
        return solve(n);
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach 3: Bottom Up 
// TC: o(n) SC:o(n)
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1 || n == 2)
            return n;

        vector<int> array(n + 1);

        array[0] = 0;
        array[1] = 1;
        array[2] = 2;

        for (int i = 3; i <= n; i++) {
            array[i] = array[i - 1] + array[i - 2];
        }
        return array[n];
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach 4: Optimization Of Bottom Up
// TC: o(n) SC:o(1)
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1 || n == 2)
            return n;

        int a = 1;
        int b = 2;
        int c = 3;

        for (int i = 3; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


