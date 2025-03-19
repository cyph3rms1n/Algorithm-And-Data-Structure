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
/////////////////////////////////////////////////////////////////////////////////
//// BFS
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        vector<int> inDegree(n,0);
        queue<int> que;
        
        for(int u=0; u<n; u++){
            for(auto& v: adj[u]){
                inDegree[v]++;
            }
        }
        
        for(int i=0; i<n; i++){
            if(inDegree[i] == 0){
                que.push(i);
            }
        }
        
        int count = 0;
        
        while(!que.empty()){
            int u = que.front();
            que.pop();
            count++;
            
            for(auto& v : adj[u]){
                inDegree[v]--;
                
                if(inDegree[v] == 0){
                    que.push(v);
                }
            }
        }
        
        if(count == n) return false;
        else return true;
    }
};
