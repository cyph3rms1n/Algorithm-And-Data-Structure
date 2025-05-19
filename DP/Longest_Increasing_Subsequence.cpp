// LC: 300. Longest Increasing Subsequence
////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach 1:
// TC: o(n^2) SC:o(n)
class Solution {
public:
    int n;
    int t[2501][2501];
    int solve(int i, int p, vector<int>& nums) {
        if (i >= n)
            return 0;

        if (p != -1 && t[i][p] != -1) {
            return t[i][p];
        }

        int take = 0;
        if (p == -1 || nums[i] > nums[p]) {
            take = 1 + solve(i + 1, i, nums);
        }

        int skip = solve(i + 1, p, nums);

        if (p != -1) {
            t[i][p] = max(take, skip);
        }

        return max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(0, -1, nums);
    }
};
