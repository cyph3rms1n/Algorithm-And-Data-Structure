//geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
//// DFS
class Solution {
  public:
  
    bool dfs(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<bool>& inRecursion){
        visited[u] = true;
        inRecursion[u] = true;
        
        for(auto& v: adj[u]){
            if(!visited[v] && dfs(adj, v, visited, inRecursion)){
                return true;
            }else if(inRecursion[v] == true){
                return true;
            }
        }
        inRecursion[u] = false;
        return false;
    }
    bool isCyclic(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        vector<bool> visited(n,false);
        vector<bool> inRecursion(n, false);
        
        for(int i = 0 ;i< n; i++){
            if(!visited[i] && dfs(adj, i, visited, inRecursion)){
                return true;
            }
        }
        return false;
    }
};
