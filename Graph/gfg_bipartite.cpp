////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// geeksforgeeks.org/problems/bipartite-graph/1
////// Using DFS
class Solution {
  public:
  
    bool checkBipartiteDFS(vector<vector<int>>& adj, int curr, vector<int>& color, int currColor){
        color[curr] = currColor;
        
        for(auto& v: adj[curr]){
          
            if(color[v] == color[curr])
                return false;
                
            if(color[v] == -1){
                int colorOfV = 1 - currColor;
                if(checkBipartiteDFS(adj,v, color, colorOfV) == false)
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        // Code here    
        int v = adj.size();
        vector<int> color(v, -1);
        
        for(int i =0; i< v; i++){
            if(color[i] == -1){
                if(checkBipartiteDFS(adj, i, color,1) == false){
                    return false;
                }
            }
        }
        return true;
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
