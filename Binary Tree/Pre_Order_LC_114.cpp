////////////////////////////////////////////////////////////////////////////////
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
    void preOrder(TreeNode* root) {
        if (root == NULL)
            return;

        result.push_back(root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preOrder(root);
        return result;
    }
};
////////////////////////////////////////////////////////////////////////////////
// Iterative Approach. Using stack
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
    void preOrder(TreeNode* root) {
        if (root == NULL)
            return;
        stack<TreeNode*> st; // stack of node
        st.push(root);

        while (!st.empty()) {
            root = st.top();
            st.pop();
            // First push right child
            // Then push left child
            // So that we can access the left child first from stack
            result.push_back(root->val);
            if (root->right != NULL) {
                st.push(root->right);
            }
            if (root->left != NULL) {
                st.push(root->left);
            }
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preOrder(root);
        return result;
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////
