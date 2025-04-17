//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
    long maxP;
    long SUM;

    int totalSum(TreeNode* root) {
        if (!root)
            return 0;

        int leftSubTreeSum = totalSum(root->left);
        int rightSubTreeSum = totalSum(root->right);
        int sum = leftSubTreeSum + rightSubTreeSum + root->val;

        return sum;
    }

    int find(TreeNode* root) {
        if (!root)
            return 0;

        int leftSum = find(root->left);
        int rightSum = find(root->right);
        int subTreeSum = root->val + leftSum + rightSum;

        int remainingSubTreeSum = SUM - subTreeSum;
        maxP = max(maxP, 1l * subTreeSum * remainingSubTreeSum);

        return subTreeSum;
    }
    int maxProduct(TreeNode* root) {
        maxP = 0;
        SUM = totalSum(root);
        if (!root)
            return 0;

        find(root);

        return maxP % (int)(1e9 + 7);
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
