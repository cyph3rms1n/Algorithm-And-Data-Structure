////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Brute Force , TC: o(n^2)
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
    void findDiff(TreeNode* root, TreeNode* child, int& maxDiff) {
        if (root == NULL || child == NULL)
            return;

        maxDiff = max(maxDiff, abs(root->val - child->val));

        findDiff(root, child->left, maxDiff);
        findDiff(root, child->right, maxDiff);
    }
    void callFindDiff(TreeNode* root, int& maxDiff) {
        if (!root)
            return;

        findDiff(root, root->left, maxDiff);
        findDiff(root, root->right, maxDiff);

        callFindDiff(root->left, maxDiff);
        callFindDiff(root->right, maxDiff);
    }
    int maxAncestorDiff(TreeNode* root) {
        int maxDiff = 0;

        callFindDiff(root, maxDiff);
        return maxDiff;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
