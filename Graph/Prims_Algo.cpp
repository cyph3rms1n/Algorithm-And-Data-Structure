///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
  public:
  typedef pair<int, int> P;
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0,0});
        vector<int>  inMST(V, false);
        
        int sum = 0;
        
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            
            int wt = p.first;
            int node = p.second;
            
            if(inMST[node] == true)
                continue;
            
            inMST[node] = true; // added in MST
            sum += wt;
            for(auto& temp : adj[node]){
                int neighbour = temp[0];
                int neighbour_wt = temp[1];
                
                if(inMST[neighbour] == false){
                    pq.push({neighbour_wt, neighbour});
                }
            }
        }
        return sum;
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
