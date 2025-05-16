// LC: 198. House Robber
////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach 1: Recursion
// TC: o(2^n) SC: o(1)

class Solution {
public:
    int solve(vector<int>& nums, int i, int n) {
        if (i >= n)
            return 0;

        int steal = nums[i] + solve(nums, i + 2, n);
        int skip = solve(nums, i + 1, n);

        return max(steal, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, 0, n);
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach 2: Recursion + Memorization [ Top - Bottom Approach ]
// TC: o(n) SC: o(n)

class Solution {
public:
    int t[101];
    int solve(vector<int>& nums, int i, int n) {
        if (i >= n)
            return 0;
        if (t[i] != -1)
            return t[i];

        int steal = nums[i] + solve(nums, i + 2, n);
        int skip = solve(nums, i + 1, n);

        return t[i] = max(steal, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, 0, n);
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach 3: Bottom - Up
// TC: o(n) SC: o(n)

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> t(n + 1, 0);
        // t[i] = max stolen money till i house
        // i = 0 : no house
        // i = 1 : 1 house
        // i = 2 : 2 house and so on
        t[0] = 0;
        t[1] = nums[0];

        for (int i = 2; i <= n; i++) {
            int steal = nums[i - 1] + t[i - 2];
            int skip = t[i - 1];

            t[i] = max(steal, skip);
        }
        return t[n];
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach 4: Bottom-Up , using constant space
// TC: o(n) SC: o(1)

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // t[i] = max stolen money till i house
        // i = 0 : no house
        // i = 1 : 1 house
        // i = 2 : 2 house and so on
        int prevPrev = 0;
        int prev = nums[0];

        for (int i = 2; i <= n; i++) {
            int steal = nums[i - 1] + prevPrev;
            int skip = prev;

            int temp = max(steal, skip);

            prevPrev = prev;
            prev = temp;
        }
        return prev;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////
