////////////////////////////////////////////////////////////////////////////////////////////
// geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
class Solution {
  public:
    void shortestDistance(vector<vector<int>>& mat) {
        // Code here
        int n = mat.size();
        // vector<vector<int>> grid;
        
        for(int i = 0; i< n; i++){
            for(int j = 0 ;j < n;j++){
                if(mat[i][j] == -1){
                    mat[i][j] = 10000;
                }
            }
        }
        
        for(int via =0; via < n; via++){
            for(int i =0; i < n; i++){
                for(int j =0; j < n; j++){
                    mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j]);
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0 ;j < n;j++){
                if(mat[i][j] == 10000){
                    mat[i][j] = -1;
                }
            }
        }
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////
