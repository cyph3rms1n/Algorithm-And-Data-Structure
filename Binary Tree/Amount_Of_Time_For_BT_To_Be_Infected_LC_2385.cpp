///////////////////////////////////////////////////////////////////////////////////////////////
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
// First Approach
class Solution {
public:
    void makeGraph(unordered_map<int, vector<int>>& adj, int parent, TreeNode* curr) {
        if (!curr)
            return ;

        if (parent != -1) {
            adj[curr->val].push_back(parent);
        }
        if (curr->left) {
            adj[curr->val].push_back(curr->left->val);
        }
        if (curr->right) {
            adj[curr->val].push_back(curr->right->val);
        }

        makeGraph(adj, curr->val, curr->left);
        makeGraph(adj, curr->val, curr->right);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;

        makeGraph(adj, -1, root);

        queue<int> q;
        unordered_set<int> visited;
        q.push(start);
        visited.insert(start);

        int min = 0;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                int curr = q.front();
                q.pop();

                for (auto& ngbr : adj[curr]) {
                    if (visited.find(ngbr) == visited.end()) {
                        q.push(ngbr);
                        visited.insert(ngbr);
                    }
                }
            }
            min++;
        }
        return min - 1;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
