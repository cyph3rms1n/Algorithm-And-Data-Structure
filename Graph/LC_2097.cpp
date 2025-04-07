////////////////////////////////////////////////////////////////////////////////////////////
// Using "Hierholzer's Algorithm". Implementation of Eular's Law

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        // step 1: Build adjacency list
        unordered_map<int, vector<int>> adj;
        // Step 2: Build indegree, outdegree
        unordered_map<int, int> inDegree,
            outDegree; // *key - node and *value - indegree/outdegree

        for (auto& pair : pairs) {
            int u = pair[0];
            int v = pair[1];

            adj[u].push_back(v);
            inDegree[v]++;
            outDegree[u]++;
        }

        // Step 3: Find start node aka source
        int startNode = pairs[0][0];

        for (auto& it : adj) {
            int node = it.first;

            if (outDegree[node] - inDegree[node] == 1) {
                startNode = node;
                break;
            }
        }

        // step 4: DFS
        vector<int> EularPath;
        stack<int> st;
        st.push(startNode);

        while (!st.empty()) {
            int curr = st.top();
            if (!adj[curr].empty()) {
                int ngbr = adj[curr].back();
                adj[curr].pop_back();
                st.push(ngbr);
            } else {
                EularPath.push_back(curr);
                st.pop();
            }
        }

        // step 5: Build result
        reverse(begin(EularPath), end(EularPath));
        vector<vector<int>> result;

        for (int i = 0; i < EularPath.size() - 1; i++) {
            result.push_back({EularPath[i], EularPath[i + 1]});
        }
        return result;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////
