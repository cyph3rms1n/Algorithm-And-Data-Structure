// LC: 213. House Robber II
///////////////////////////////////////////////////////////////////////////////////////
// Approach 1: Recursion + Memorization
// TC: o(n) SC: o(n)

class Solution {
public:
    int t[101];
    int solve(vector<int>& nums, int i, int n) {
        if (i > n)
            return 0;
        if (t[i] != -1)
            return t[i];

        int steal = nums[i] + solve(nums, i + 2, n);
        int skip = solve(nums, i + 1, n);

        return t[i] = max(steal, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
            
        memset(t, -1, sizeof(t));
        int max1 = solve(nums, 0, n - 2);

        memset(t, -1, sizeof(t));
        int max2 = solve(nums, 1, n - 1);
        return max(max1, max2);
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach 2: Bottom - Up
// TC: o(n) SC: o(n)

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        vector<int> t(n + 1, 0);
        t[0] = 0;

        for (int i = 1; i <= n - 1; i++) {
            int steal = nums[i - 1] + ((i - 2 >= 0) ? t[i - 2] : 0);
            int skip = t[i - 1];

            t[i] = max(steal, skip);
        }
        int result1 = t[n - 1];

        t.clear();

        t[0] = 0;
        t[1] = 0;

        for (int i = 2; i <= n; i++) {
            int steal = nums[i - 1] + ((i - 2 >= 0) ? t[i - 2] : 0);
            int skip = t[i - 1];

            t[i] = max(steal, skip);
        }
        int result2 = t[n];

        return max(result1, result2);
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
