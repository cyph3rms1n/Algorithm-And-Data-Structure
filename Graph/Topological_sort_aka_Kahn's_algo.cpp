// geeksforgeeks.org/problems/topological-sort/1
// using BFS
class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        int n = adj.size();
        vector<int> inDegree(n,0);
        queue<int> que;
        vector<int> result;
      
        // 1. Fill inDegree
        for(int u=0; u<n; u++){
            for(auto& v : adj[u]){
                inDegree[v]++;
            }
        }
        
        // 2. Push all the values having inDegree 0
        for(int i=0; i<n; i++){
            if(inDegree[i] == 0){
                que.push(i);
            }
        }
        
        // 3. Implement Simple BFS
        while(!que.empty()){
            int u = que.front();
            result.push_back(u);
            que.pop();
            
            for(auto& v : adj[u]){
                inDegree[v]--;
                if(inDegree[v] == 0){
                    que.push(v);
                }
            }
        }
        return result;
    }
};
