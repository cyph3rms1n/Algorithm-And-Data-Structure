// LC: 2926. Maximum Balanced Subsequence Sum
///////////////////////////////////////////////////////////////////////////////////////
// Approach 1: Recursion + Memorization
// TC: o(n^2) SC: o(n^2)

class Solution {
public:
    int n;
    unordered_map<string, long long> mp;
    long long solve(int i, int p, vector<int>& nums) {
        if (i >= n) {
            return 0;
        }

        string key = to_string(p) + "_" + to_string(i);
        if (mp.find(key) != mp.end()) {
            return mp[key];
        }

        long long take = INT_MIN;
        long long skip = INT_MIN;

        if (p == -1 || nums[i] - i >= nums[p] - p) {
            take = nums[i] + solve(i + 1, i, nums);
        }
        skip = solve(i + 1, p, nums);

        return mp[key] = max<long long>(take, skip);
    }
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        n = nums.size();
        int maxE = *max_element(begin(nums), end(nums));
        if (maxE <= 0)
            return maxE;
        return solve(0, -1, nums);
    }
};
///////////////////////////////////////////////////////////////////////////////////////
// Approach 2: Bottom Up
// TC: o(n^2) SC: o(n^2)

class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        int maxE = *max_element(begin(nums), end(nums));

        if (maxE <= 0) {
            return maxE;
        }
        vector<long long> t(n);

        for (int i = 0; i < n; i++) {
            t[i] = nums[i];
        }

        long long maxSum = INT_MIN;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] - i >= nums[j] - j) {
                    t[i] = max(t[i], t[j] + nums[i]);
                    maxSum = max(maxSum, t[i]);
                }
            }
        }
        return maxSum > maxE ? maxSum : maxE;
    }
};
///////////////////////////////////////////////////////////////////////////////////////
// Approach 3: Optimal LIS
// TC: o(nlogn) SC: o(n)

class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        map<int, long long> mp;

        long long ans = INT_MIN;
        
        for(int i = 0; i < n; i++){
            auto it = mp.upper_bound(nums[i]-i); //Find the element just greater than nums[i]-i;

            long long cur_ans = nums[i];

            if(it != mp.begin()) {
                it--;
                cur_ans += (*it).second;
            }
            mp[nums[i]-i] = max(mp[nums[i]-i], cur_ans);

            it = mp.upper_bound(nums[i]-i);

            while(it != mp.end() && (*it).second <= cur_ans) {
                 mp.erase(it++);
            }

            ans = max(ans, cur_ans);
        }

        return ans;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////
