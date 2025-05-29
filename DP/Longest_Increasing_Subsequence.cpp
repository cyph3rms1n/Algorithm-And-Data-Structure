// LC: 300. Longest Increasing Subsequence
////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach 1: Recursion + Memorization
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
////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach 2: Bottom Up
// TC: o(n^2) SC:o(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n, 1);

        int maxU = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    t[i] = max(t[i], t[j] + 1);
                    maxU = max(maxU, t[i]);
                }
            }
        }
        return maxU;
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach 3: Patience Sorting
// TC: o(nlogn) SC:o(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted;

        for (int i = 0; i < n; i++) {
            auto it = lower_bound(sorted.begin(), sorted.end(), nums[i]);
            if (it == sorted.end()) {
                sorted.push_back(nums[i]);
            } else {
                *it = nums[i];
            }
        }
        return sorted.size();
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
