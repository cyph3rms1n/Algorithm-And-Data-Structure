/////////////////////////////////////////////////////////////////////////////////////////////////
// geeksforgeeks.org/problems/euler-circuit-in-a-directed-graph/1
// Eular's Path and circuit

class Solution {
public:
    bool isConnected(int v, vector<int> adj[]) {

        int nonZeroDegreeVertex = -1;
        for (int i = 0; i < v; i++) {
            if (adj[i].size() > 0) {
                nonZeroDegreeVertex = i;
                break;
            }
        }

        // If the graph has no edges
        if (nonZeroDegreeVertex == -1)
            return true;

        vector<bool> visited(v, false);

        // Start DFS from nonZeroDegreeVertex
        DFS(adj, nonZeroDegreeVertex, visited);

        // Check if all nonzeroDegreeVertices are visited or not
        for (int i = 0; i < v; i++) {
            if (visited[i] == false && adj[i].size() > 0) {
                return false;
            }
        }
        return true;
    }

    void DFS(vector<int> adj[], int u, vector<bool>& visited) {
        visited[u] = true;

        for (auto it = adj[u].begin(); it != adj[u].end(); it++) {
            int neighbour = *it;
            if (visited[neighbour] == false) {
                DFS(adj, neighbour, visited);
            }
        }
    }
    bool isEularCircuitExist(int v, vector<int> adj[]) {
        if (isConnected(v, adj) == false) {
            return 0;
        }

        int oddDegreeCount = 0;

        for (int i = 0; i < v; i++) {
            if (adj[i].size() % 2 != 0) {
                oddDegreeCount++;
            }
        }

        if (oddDegreeCount == 0)
            return 1;
        return 0;
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
