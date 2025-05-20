// lc: 1911. Maximum Alternating Subsequence Sum
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach 1: Recursion + Memorization
// TC: o(n) SC: O(n)


class Solution {
public:
    typedef long long ll;
    ll t[100001][2];
    ll n;
    ll solve(int idx, vector<int>& nums, bool flag) {
        if (idx >= n)
            return 0;

        if (t[idx][flag] != -1)
            return t[idx][flag];

        ll skip = solve(idx + 1, nums, flag);

        ll val = nums[idx];
        if (flag == false)
            val = -val;

        ll take = val + solve(idx + 1, nums, !flag);

        return t[idx][flag] = max(take, skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(0, nums, true);
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach 2: Bottom - Up
// TC: o(n) SC: O(n)
// Reference : youtube.com/watch?v=eKo0TzMDeEo&list=PLpIkg8OmuX-JhFpkhgrAwZRtukO0SkwAt&index=10&ab_channel=codestorywithMIK

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long>> t(n + 1, vector<long>(2, 0)); // 0: even 1: odd

        for (int i = 1; i <= n; i++) {
            t[i][0] = max(t[i - 1][1] - nums[i - 1], t[i - 1][0]);
            t[i][1] = max(t[i - 1][0] + nums[i - 1], t[i - 1][1]);
        }

        return max(t[n][0], t[n][1]);
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
