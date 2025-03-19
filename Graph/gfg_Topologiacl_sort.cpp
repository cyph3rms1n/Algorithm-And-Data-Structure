// geeksforgeeks.org/problems/topological-sort/1
// Topological Sort (Using BFS)
class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    
    void DFS(vector<vector<int>>& adj, int u, vector<bool>& visited, stack<int>& st){
        visited[u] = true;
        
        for(auto& v: adj[u]){
            if(!visited[v]){
                DFS(adj, v, visited, st);
            }
        }
        st.push(u);
    }
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        int n = adj.size();
        vector<bool> visited(n,false);
        stack<int> st;
        
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                DFS(adj, i, visited, st);
            }
        }
        vector<int> result;
        
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};
