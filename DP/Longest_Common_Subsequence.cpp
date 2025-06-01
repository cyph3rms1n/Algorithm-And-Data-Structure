// LC: 1143. Longest Common Subsequence
///////////////////////////////////////////////////////////////////////////////
// Approach 1: Recursion + Memorization
// TC: o(2 ^ (m + n)) SC: o(m * n)
class Solution {
public:
    int t[1001][1001];
    int solve(string& s1, string& s2, int i, int j) {
        if (i >= s1.length() || j >= s2.length()) {
            return 0;
        }
        if (t[i][j] != -1) {
            return t[i][j];
        }
        if (s1[i] == s2[j]) {
            return t[i][j] = 1 + solve(s1, s2, i + 1, j + 1);
        }
        return t[i][j] = max(solve(s1, s2, i + 1, j), solve(s1, s2, i, j + 1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(t, -1, sizeof(t));
        return solve(text1, text2, 0, 0);
    }
};
/////////////////////////////////////////////////////////////////////////////////////
// Approach 2: Botttom -Up
// TC: o(m * n) SC: o(m * n)

class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();

        vector<vector<int>> t(m + 1, vector<int>(n + 1));

        for (int i = 0; i < m + 1; i++) {
            t[i][0] = 0;
        }
        for (int j = 0; j < n + 1; j++) {
            t[0][j] = 0;
        }

        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    t[i][j] = 1 + t[i - 1][j - 1];
                } else {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }
        return t[m][n];
    }
};
/////////////////////////////////////////////////////////////////////////////////////
