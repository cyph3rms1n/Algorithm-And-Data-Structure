//////////////////////////////////////////////////////////////
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();

        vector<int> pairSum(n - 1, 0);

        for (int i = 0; i < n - 1; i++) {
            pairSum[i] = weights[i] + weights[i + 1];
        }

        sort(begin(pairSum), end(pairSum));
        long maxSum = 0;
        long minSum = 0;

        for (int i = 0; i < k - 1; i++) {
            minSum += pairSum[i];
            maxSum += pairSum[n - i - 2];
        }

        return maxSum - minSum;
    }
};
/////////////////////////////////////////////////////////////
