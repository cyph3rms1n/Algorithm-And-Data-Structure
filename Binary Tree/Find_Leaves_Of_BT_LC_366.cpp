///////////////////////////////////////////////////////////////////////////////////////////////
/////////////////// PREMIUM LeetCode Question ///////////////////////////////////////////////
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
    int findHeight(TreeNode* root, unordered_map<int, vector<int>>& mp) {
        if (root == NULL)
            return 0;

        int LH = findHeight(root->left, mp);
        int RH = findHeight(root->right, mp);

        int H = 1 + max(LH, RH);
        mp[H].push_back(root->val);
        return H;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> result;
        unordered_map<int, vector<int>> mp;

        findHeight(root, mp);

        for (auto& itr : mp) {
            result.push_back(itr.second);
        }

        return result;
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////////
