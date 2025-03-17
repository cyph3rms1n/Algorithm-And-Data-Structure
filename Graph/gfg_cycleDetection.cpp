//geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
// undirected graph
// dfs
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(vector<vector<int>>& adj, int u, vector<bool>& visited, int parent){
        visited[u] = true;
        
        for(auto& v: adj[u]){
            if(v == parent) continue;
            
            if(visited[v] || dfs(adj,v,visited,u)){
                return true;
            }
        }
        return false;
    }
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<bool> visited(n,false);
        
        for(int i = 0; i< n;i++){
            if(!visited[i]){
                if(dfs(adj, i, visited, -1)){
                    return true;
                }
            }
        }
        return false;
    }
};
