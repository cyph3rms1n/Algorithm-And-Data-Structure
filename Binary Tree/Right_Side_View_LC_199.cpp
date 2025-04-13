/////////////////////////////////////////////////////////////////////////////////////////
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
//  Using Level Order Traversal
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == NULL)
            return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            TreeNode* node = NULL;
            while (n--) {
                node = q.front();
                q.pop();

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            result.push_back(node->val);
        }
        return result;
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Using DFS
class Solution {
public:
    void preOrder(TreeNode* root, int level, vector<int>& result) {
        if (root == NULL)
            return;

        if (result.size() < level) {
            result.push_back(root->val);
        }

        preOrder(root->right, level + 1, result);
        preOrder(root->left, level + 1, result);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;

        preOrder(root, 1, result);
        return result;
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
