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
