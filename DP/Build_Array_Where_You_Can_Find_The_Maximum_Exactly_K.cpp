// LC: 1420. Build Array Where You Can Find The Maximum Exactly K
////////////////////////////////////////////////////////////////////////////////////////////
// Approach !: Recursion + Memorization
// TC: o(N * K * M * M )   SC: o(N * K * M)

class Solution {
public:
    int N, M, K;
    int MOD = 1e9 + 7;
    int t[51][51][101];
    int solve(int idx, int cost, int maxi) {
        if (idx == N) {
            if (cost == K)
                return 1;
            else
                return 0;
        }
        if (t[idx][cost][maxi] != -1)
            return t[idx][cost][maxi];
        int result = 0;

        for (int i = 1; i <= M; i++) {
            if (i > maxi) {
                result = (result + solve(idx + 1, cost + 1, i)) % MOD;
            } else {
                result = (result + solve(idx + 1, cost, maxi)) % MOD;
            }
        }
        return t[idx][cost][maxi] = result % MOD;
    }

    int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K = k;
        memset(t, -1, sizeof(t));
        return solve(0, 0, 0);
    }
};
