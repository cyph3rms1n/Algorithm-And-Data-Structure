// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution {
  public:
    void dfs(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<int>& result){
        if(visited[u] == true) return;
        visited[u] = true;
        result.push_back(u);
        
        for(auto& v: adj[u]){
            if(!visited[v]){
                dfs(adj, v, visited, result);
            }
        }
    }
    
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<bool> visited(n, false);
        vector<int> result;
        
        dfs(adj, 0, visited, result);
        return result;
    }
};
