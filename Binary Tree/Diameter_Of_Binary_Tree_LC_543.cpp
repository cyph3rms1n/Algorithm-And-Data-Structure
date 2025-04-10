////////////////////////////////////////////////////////////////////////////////
// T.C : o(n^2)
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
    int find(TreeNode* root, int& diameter) {
        if (root == NULL)
            return 0;

        int maxLeft = find(root->left, diameter);
        int maxRight = find(root->right, diameter);

        diameter = max(maxLeft + maxRight, diameter);

        return 1 + max(maxLeft, maxRight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        find(root, diameter);
        return diameter;
    }
};
/////////////////////////////////////////////////////////////////////////////////////////
