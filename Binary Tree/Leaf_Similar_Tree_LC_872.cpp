/////////////////////////////////////////////////////////////////////////////////////////////////
// Using vector
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
    void saveLeaf(TreeNode* root, vector<int>& store) {
        if (!root)
            return;

        saveLeaf(root->left, store);
        if (!root->left && !root->right) {
            store.push_back(root->val);
        }
        saveLeaf(root->right, store);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> store1, store2;
        saveLeaf(root1, store1);
        saveLeaf(root2, store2);

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
// Using string
class Solution {
public:
    void saveLeaf(TreeNode* root, string& s) {
        if (!root)
            return;

        saveLeaf(root->left, s);
        if (!root->left && !root->right) {
            int value = root->val;
            s += to_string(root->val) + "_";
        }
        saveLeaf(root->right, s);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1, s2;
        saveLeaf(root1, s1);
        saveLeaf(root2, s2);

        if (s1 != s2)
            return false;

        return true;
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
