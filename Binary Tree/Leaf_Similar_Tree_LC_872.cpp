/////////////////////////////////////////////////////////////////////////////////////////////////
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
    void firstTree(TreeNode* root, vector<int>& store1) {
        if (!root)
            return;

        firstTree(root->left, store1);
        if (!root->left && !root->right) {
            store1.push_back(root->val);
        }
        firstTree(root->right, store1);
    }

    void secondTree(TreeNode* root, vector<int>& store2) {
        if (!root)
            return;

        secondTree(root->left, store2);
        if (!root->left && !root->right) {
            store2.push_back(root->val);
        }
        secondTree(root->right, store2);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> store1, store2;
        firstTree(root1, store1);
        secondTree(root2, store2);

        if (store1.size() != store2.size())
            return false;

        for (size_t i = 0; i < store1.size(); i++) {
            if (store1[i] != store2[i])
                return false;
        }
        return true;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
