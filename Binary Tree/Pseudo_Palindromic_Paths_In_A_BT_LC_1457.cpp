//////////////////////////////////////////////////////////////////////////////////////////
// First Approach
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, vector<int>& count, int& result) {
        if (!root)
            return;
        count[root->val]++;

        if (!root->left && !root->right) {
            int oddFreq = 0;
            for (int i = 1; i <= 9; i++) {
                if (count[i] % 2 != 0)
                    oddFreq++;
            }
            if (oddFreq <= 1) {
                result += 1;
            }
        }

        solve(root->left, count, result);
        solve(root->right, count, result);

        count[root->val]--;
    }
    int pseudoPalindromicPaths(TreeNode* root) {
        vector<int> count(10, 0);
        int result = 0;
        solve(root, count, result);
        return result;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Second Approach
