////////////////////////////////////////////////////////////////////////////////////////////
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;

        if (!p || !q || p->val != q->val)
            return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
///////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    void find1(TreeNode* p, vector<int>& r1) {
        if (p == NULL) {
            r1.push_back(INT_MIN);
            return;
        }

        r1.push_back(p->val);
        find1(p->left, r1);
        find1(p->right, r1);
    }

    void find2(TreeNode* q, vector<int>& r2) {
        if (q == NULL) {
            r2.push_back(INT_MIN);
            return;
        }

        r2.push_back(q->val);
        find2(q->left, r2);
        find2(q->right, r2);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> r1, r2;

        find1(p, r1);
        find2(q, r2);

        if (r1 == r2)
            return true;
        else
            return false;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
