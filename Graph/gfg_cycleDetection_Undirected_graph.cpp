//geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
//// dfs
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
//// bfs
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(vector<vector<int>>& adj, int u, vector<bool>& visited){
        queue<pair<int,int>> que;
        que.push({u, -1});
        visited[u] = true;
        
        while(!que.empty()){
            pair<int,int> temp = que.front();
            que.pop();
            
            int source = temp.first;
            int parent = temp.second;
            
            for(auto& v: adj[source]){
                if(!visited[v]){
                    visited[v] = true;
                    que.push({v,source});
                }else if(v != parent){
                    return true;
                }
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
                if(bfs(adj, i, visited)){
                    return true;
                }
            }
        }
        return false;
    }
};
