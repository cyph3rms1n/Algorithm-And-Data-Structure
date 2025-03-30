////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (x == parent[x])
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent)
            return;

        if (rank[x_parent] > rank[y_parent])
            parent[y_parent] = x_parent;

        else if (rank[x_parent] < rank[y_parent])
            parent[x_parent] = y_parent;

        else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;
        int comp = n;
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (auto& c : connections) {
            int first = c[0];
            int second = c[1];

            int first_parent = find(first);
            int second_parent = find(second);

            if (first_parent != second_parent) {
                Union(first_parent, second_parent);
                comp--;
            }
        }
        return comp - 1;
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////////
