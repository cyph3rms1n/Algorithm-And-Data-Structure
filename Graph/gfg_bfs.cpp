//https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    
    void bfs(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<int>& result){
        queue<int> que;
        que.push(u);
        visited[u] = true;
        result.push_back(u);
        
        while(!que.empty()){
            int u = que.front();
            que.pop();
            
            for(auto& v : adj[u]){
                if(!visited[v]){
                    que.push(v);
                    visited[v] = true;
                    result.push_back(v);
                }
            }
        }
    }
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        int n = adj.size();
        vector<bool> visited(n, false);
        vector<int> result;
        
        bfs(adj, 0, visited, result);
        return result;
    }
};
