//////////////////////////////////////////////////////////////////////////////////////////
// geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
class Solution {
  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        
        vector<int> result(V,1e8);
        result[src] = 0;
        for(int i =0; i< V-1; i++){
            for(auto& edge : edges){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                if(result[u] != 1e8 && result[u] + w < result[v]){
                    result[v] = result[u] + w;
                }
            }
        }
        
        for(auto& edge : edges){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                if(result[u] != 1e8 && result[u] + w < result[v]){
                    return {-1};
                }
        }
        return result;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////
