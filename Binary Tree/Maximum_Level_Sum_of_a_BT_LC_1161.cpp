/////////////////////////////////////////////////////////////////////////////////////////////////////
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
    typedef long long ll;
    int maxLevelSum(TreeNode* root) {
        ll sum = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        ll level = 0;
        int currentLevel = 1;
        while (!q.empty()) {
            ll temp = 0;
            ll n = q.size();
            while (n--) {
                TreeNode* node = q.front();
                q.pop();
                temp += node->val;

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }

            if (sum < temp) {
                sum = temp;
                level = currentLevel;
            }
            currentLevel++;
        }
        return level;
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
