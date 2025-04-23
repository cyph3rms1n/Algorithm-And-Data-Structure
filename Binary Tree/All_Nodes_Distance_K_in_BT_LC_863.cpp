//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // 1. Converting into  undirected binary tree
    void findParent(TreeNode* root,
                    unordered_map<TreeNode*, TreeNode*>& parent) {
        if (!root)
            return;

        if (root->left) {
            parent[root->left] = root;
            findParent(root->left, parent);
        }

        if (root->right) {
            parent[root->right] = root;
            findParent(root->right, parent);
        }
    }

    // 2. Implementing BFS to find the node at kth distance
    // also above the target value (parent of the target)
    void BFS(TreeNode* target, int k, vector<int>& result,
             unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<int> visited;
        visited.insert(target->val);
        while (!q.empty()) {
            int n = q.size();
            if (k == 0)
                break;
            while (n--) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left && !visited.count(curr->left->val)) {
                    q.push(curr->left);
                    visited.insert(curr->left->val);
                }

                if (curr->right && !visited.count(curr->right->val)) {
                    q.push(curr->right);
                    visited.insert(curr->right->val);
                }

                if (parent.count(curr) && !visited.count(parent[curr]->val)) {
                    q.push(parent[curr]);
                    visited.insert(parent[curr]->val);
                }
            }
            k--;
        }

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            result.push_back(node->val);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        findParent(root, parent);

        vector<int> result;

        BFS(target, k, result, parent);

        return result;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
