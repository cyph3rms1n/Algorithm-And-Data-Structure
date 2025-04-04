//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
  public:
    vector<int> parent;
    vector<int> rank;
    int find(int u){
        if(u == parent[u]) return u;
        
        return parent[u] = find(parent[u]);
    }
    
    void Union(int u, int v){
        int parent_u = find(u);
        int parent_v = find(v);
        
        if(parent_u == parent_v){
            return;
        }else if(rank[parent_u] > rank[parent_v]){
            parent[parent_v] = parent_u;
        }else if(rank[parent_u] < rank[parent_v]){
            parent[parent_u] = parent_v;
        }else{
            parent[parent_u] = parent_v;
            rank[parent_v]++;
        }
        
    }
    int kruskals(vector<vector<int>>& vec){
        int sum = 0;
        
        for(auto& temp : vec){
            int u = temp[0];
            int v = temp[1];
            int wt = temp[2];
            
            int parent_u = find(u);
            int parent_v = find(v);
            
            if(parent_u != parent_v){
                Union(u,v);
                sum += wt;
            }
        }
        return sum;
    }

    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        parent.resize(V);
        rank.resize(V,0);
        
        for(int i= 0; i < V; i++){
            parent[i] = i;
        }
        vector<vector<int>> vec;
        
        for(int u = 0; u < V; u++){
            for(auto& temp : adj[u]){
                int v = temp[0];
                int wt = temp[1];
                
                vec.push_back({u,v,wt});
            }
        }
        auto comparator = [&](vector<int>& vec1, vector<int>& vec2){
            return vec1[2] < vec2[2];
        };
        sort(begin(vec), end(vec), comparator);
        
        return kruskals(vec);
        
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
