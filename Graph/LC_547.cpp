///////////////////////////////////////////////////////////////////////////////////
//// Using Extra Space for adjacency list of the grapgh
class Solution {
public:
    int n;
    void DFS(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited) {
        visited[u] = true;
        for (auto& v : adj[u]) {
            if (!visited[v]) {
                DFS(adj, v, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, vector<int>> adj;
        int count = 0;
        n = isConnected.size();
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                DFS(adj, i, visited);
                count++;
            }
        }
        return count;
    }
};
//////////////////////////////////////////////////////////////////////////////////////
//// Without using adjacency list
class Solution {
public:
    int n;
    void DFS(vector<vector<int>>& isConnected, int u, vector<bool>& visited) {
        visited[u] = true;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && isConnected[u][v] == 1) {
                DFS(isConnected, v, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        n = isConnected.size();
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                DFS(isConnected, i, visited);
                count++;
            }
        }
        return count;
    }
};
/////////////////////////////////////////////////////////////////////////////////////
