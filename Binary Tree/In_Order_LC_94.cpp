//////////////////////////////////////////////////////////////////////////////////////
// Recursive Approach
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
    vector<int> result;
    void inOrder(TreeNode* root) {
        if (root == NULL)
            return;
        inOrder(root->left);
        result.push_back(root->val);
        inOrder(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inOrder(root);
        return result;
    }
};
///////////////////////////////////////////////////////////////////////////////////
// Iterative Approach. Using Stack
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
    vector<int> result;
    void inOrder(TreeNode* root) {
        if (root == NULL)
            return;

        stack<TreeNode*> st;
        TreeNode* node = root;

        while (true) {
            if (node != NULL) {
                st.push(node);
                node = node->left;
            } else {
                if (st.empty())
                    break;

                node = st.top();
                st.pop();

                result.push_back(node->val);
                node = node->right;
            }
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inOrder(root);
        return result;
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////
