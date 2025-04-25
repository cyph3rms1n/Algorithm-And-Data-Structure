//////////////////////////////////////////////////////////////////////////////////////////////////
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
    pair<int, int> Solve(TreeNode* root, int& result) {
        if (!root)
            return {0, 0};

        auto pL = Solve(root->left, result);
        auto pR = Solve(root->right, result);

        int totalSum = pL.first + pR.first + root->val;
        int totalCount = pL.second + pR.second + 1;

        if (root->val == (totalSum / totalCount)) {
            result++;
        }
        return {totalSum, totalCount};
    }
    int averageOfSubtree(TreeNode* root) {
        int result = 0;
        Solve(root, result);
        return result;
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////
