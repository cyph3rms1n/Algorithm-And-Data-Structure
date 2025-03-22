///////////////////////////////////////////////////////////////////////////////////////////////////////
// Using DFS:
class Solution {
public:
    void dfs(int i, unordered_map<int, vector<int>>& adj, vector<bool>& visited, int& v, int& e) {
        visited[i] = true;
        v++;
        e += adj[i].size();

        for (auto& n : adj[i]) {
            if (!visited[n]) {
                dfs(n, adj, visited, v, e);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(n, false);
        int result = 0;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < n; i++) {
            if (visited[i] == true)
                continue;

            int v = 0;
            int e = 0;
            dfs(i, adj, visited, v, e);

            if ((v * (v - 1) / 2) == e / 2) {
                result++;
            }
        }
        return result;
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////
