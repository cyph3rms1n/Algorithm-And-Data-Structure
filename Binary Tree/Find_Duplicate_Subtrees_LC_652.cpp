////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
    string getSubTreeString(TreeNode* root, unordered_map<string, int>& mp, vector<TreeNode*>& result) {
        if (!root)
            return "N";

        string s = to_string(root->val) + "," + getSubTreeString(root->left, mp, result) + "," + getSubTreeString(root->right, mp, result);

        if (mp[s] == 1) {
            result.push_back(root);
        }
        mp[s]++;

        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> result;
        unordered_map<string, int> mp;

        getSubTreeString(root, mp, result);

        return result;
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
