////////////////////////////////////////////////////////////////////////////////////////
// Using Dijkstra's Algorithm
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto& t : times) {
            int u = t[0];
            int v = t[1];
            int w = t[2];

            adj[u].push_back({v, w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> result(n + 1, INT_MAX);
        result[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto& vec : adj[node]) {
                int adjNode = vec.first;
                int w = vec.second;

                if ((d + w) < result[adjNode]) {
                    result[adjNode] = d + w;
                    pq.push({d + w, adjNode});
                }
            }
        }
        int ans = INT_MIN;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, result[i]);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
