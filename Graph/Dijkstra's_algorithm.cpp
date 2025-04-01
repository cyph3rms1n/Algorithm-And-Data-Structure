///////////////////////////////////////////////////////////////////////////////////////////////////
// geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
// using priority queue
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        int v = adj.size();
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> result(v,INT_MAX);
        
        result[src] = 0;
        pq.push({0,src});
        
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            for(auto& vec: adj[node]){
                int adjNode = vec.first;
                int weight = vec.second;
                
                if((d+weight) < result[adjNode]){
                    result[adjNode] = d + weight;
                    pq.push({d+weight, adjNode});
                }
            }
        }
        return result;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////
// Using ordered set
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        int v = adj.size();
        
        set<pair<int,int>> st;
        vector<int> result(v,INT_MAX);
        
        result[src] = 0;
        st.insert({0,src});
        
        while(!st.empty()){
            auto& it = *st.begin();
            int d = it.first;
            int node = it.second;
            
            st.erase(it);
            
            for(auto& vec: adj[node]){
                int adjNode = vec.first;
                int weight = vec.second;
                
                if((d + weight) < result[adjNode]){
                    if(result[adjNode] != INT_MAX){
                        st.erase({result[adjNode], adjNode});
                        /*
                            auot& iter = st.find({result[adjNode], adjNode});
                            st.erase(iter);
                        */
                    }
                    result[adjNode] = d + weight;
                    st.insert({d + weight, adjNode});
                }
            }
        }
        return result;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////
