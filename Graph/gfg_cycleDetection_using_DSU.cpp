//////////////////////////////////////////////////////////////////////////////////////
class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
    
    vector<int> parent;
    vector<int> rank;
    
    // Find the parent (using compressed parth mechanism)
    int find(int i){
        if(i == parent[i]){
            return i;
        }
        
        return parent[i] = find(parent[i]);
    }
    
    // Union (Rank method implementd)
    void Union(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);
        
        if(x_parent == y_parent){
            return;
        }
        
        if(rank[x_parent] > rank[y_parent]){
            
            parent[y_parent] = x_parent;
            
        }else if(rank[x_parent] < rank[y_parent]){
            
            parent[x_parent] = y_parent;
            
        }else{
            
            parent[y_parent] = x_parent;
            rank[x_parent] += 1;
            
        }
    }
    
    
	int detectCycle(int V, vector<int>adj[])
	{
	    parent.resize(V);
	    rank.resize(V);
	    
	    for(int i =0; i< V; i++){
	        parent[i] = i;
	        rank[i] = 1;
	    }
	    
	    for(int u = 0; u < V; u++){
	        for(auto& v: adj[u]){
	            if( u < v){
	                int parent_u = find(u);
	                int parent_v = find(v);
	                
	                if(parent_u == parent_v)
	                    return true;
	                    
	               Union(u, v);
	            }
	        }
	    }
	    return false;
	}
};
////////////////////////////////////////////////////////////////////////////////////////////////////
