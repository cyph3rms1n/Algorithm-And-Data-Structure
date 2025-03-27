///////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool check(unordered_map<int, vector<int>>& adj, int n, vector<int>& inDegree) {
        queue<int> que;
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                que.push(i);
            }
        }

        while (!que.empty()) {
            int u = que.front();
            que.pop();
            count++;

            for (auto& v : adj[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    que.push(v);
                }
            }
        }

        return (count == n);
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(numCourses, 0);

        for (auto& vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
            inDegree[a]++;
        }

        return check(adj, numCourses, inDegree);
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////
