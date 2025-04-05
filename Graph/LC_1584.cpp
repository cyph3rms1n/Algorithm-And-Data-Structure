////////////////////////////////////////////////////////////////////////////////////////////////////////
// Using Prim's Algorithm
class Solution {
public:
    typedef pair<int, int> P;
    int findCost(vector<vector<P>>& adj, int n) {
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});
        vector<bool> inMST(n, false);
        int cost = 0;
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            int wt = p.first;
            int node = p.second;

            if (inMST[node] == true)
                continue;

            inMST[node] = true;
            cost += wt;

            for (auto& temp : adj[node]) {
                int neighbour = temp.first;
                int neighbour_wt = temp.second;

                if (inMST[neighbour] == false) {
                    pq.push({neighbour_wt, neighbour});
                }
            }
        }
        return cost;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<P>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int dist = abs(x1 - x2) + abs(y1 - y2);

                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }
        return findCost(adj, n);
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////////////
// Using Kruskal's Algorithm
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
        int parent_x = find(x);
        int parent_y = find(y);

        if (parent_x == parent_y)
            return;
        else if (rank[parent_x] > rank[parent_y]) {
            parent[parent_y] = parent_x;
        } else if (rank[parent_x] < rank[parent_y]) {
            parent[parent_x] = parent_y;
        } else {
            parent[parent_y] = parent_x;
            rank[parent_x]++;
        }
    }

    int kruskals(vector<vector<int>>& vec) {
        int sum = 0;
        for (auto& temp : vec) {
            int u = temp[0];
            int v = temp[1];
            int wt = temp[2];

            int parent_u = find(u);
            int parent_v = find(v);

            if (parent_u != parent_v) {
                Union(u, v);
                sum += wt;
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> vec;
        int V = points.size();
        parent.resize(V);
        rank.resize(V, 0);

        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                vec.push_back({i, j, dist});
            }
        }

        auto comparator = [&](vector<int>& vec1, vector<int>& vec2){ 
            return vec1[2] < vec2[2]; 
        };

        sort(begin(vec), end(vec), comparator);
        return kruskals(vec);
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////
