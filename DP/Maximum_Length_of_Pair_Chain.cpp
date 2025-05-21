// LC: 646. Maximum Length of Pair Chain
///////////////////////////////////////////////////////////////////////////////////////////////////
// Approach 1: Recursion + Memorization
// TC: o(n) SC: o(n)

class Solution {
public:
    int n;
    int t[1001][1001];
    int solve(int i, int p, vector<vector<int>>& pairs) {
        if (i >= n)
            return 0;

        if (p != -1 && t[i][p] != -1) {
            return t[i][p];
        }
        int take = 0;

        if (p == -1 || pairs[i][0] > pairs[p][1]) {
            take = 1 + solve(i + 1, i, pairs);
        }
        int skip = solve(i + 1, p, pairs);
        if (p != -1) {
            return t[i][p] = max(take, skip);
        }
        return max(take, skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        n = pairs.size();
        memset(t, -1, sizeof(t));
        sort(begin(pairs), end(pairs));
        return solve(0, -1, pairs);
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////////
// Approach 1: Recursion + Memorization
// TC: o(n) SC: o(n)
