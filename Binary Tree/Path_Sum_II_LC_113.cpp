///////////////////////////////////////////////////////////////////////////////////////////////
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
    void fill(TreeNode* root, int sum, vector<int> temp, int targetSum, vector<vector<int>>& result) {
        if (root == NULL)
            return;

        sum += root->val;
        temp.push_back(root->val);

        if (root->left == NULL && root->right == NULL) {
            if (sum == targetSum) {
                result.push_back(temp);
            }
            return;
        }

        fill(root->left, sum, temp, targetSum, result);
        fill(root->right, sum, temp, targetSum, result);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        int sum = 0;
        vector<int> temp;

        fill(root, sum, temp, targetSum, result);
        return result;
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
