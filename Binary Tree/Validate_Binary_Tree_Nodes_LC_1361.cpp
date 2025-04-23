///////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:

    // Property of binary tree:
    // 1. Single Root
    // 2. Single parent
    // 3. No cycle
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<vector<int>> adj(n);
        unordered_map<int, int> childToParent;

        // Find the parent of all node

        for (int i = 0; i < n; i++) {
            int node = i;
            int leftC = leftChild[i];
            int rightC = rightChild[i];

            if (leftC != -1) {
                adj[node].push_back(leftC);
                if (childToParent.find(leftC) != childToParent.end()) {
                    return false;
                }
                childToParent[leftC] = i;
            }

            if (rightC != -1) {
                adj[node].push_back(rightC);
                if (childToParent.find(rightC) != childToParent.end()) {
                    return false;
                }
                childToParent[rightC] = i;
            }
        }

        // Find the root of the tree
        int root = -1;

        for (int i = 0; i < n; i++) {
            if (childToParent.find(i) == childToParent.end()) {
                if (root != -1)
                    return false;
                root = i;
            }
        }

        // If there is no root
        if (root == -1)
            return false;

        int count = 1;

        queue<int> q;
        vector<bool> visited(n, false);

        q.push(root);
        visited[root] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto& v : adj[node]) {
                if (visited[v])
                    return false;

                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                    count++;
                }
            }
        }
        if (count == n)
            return true;
        else
            return false;
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
