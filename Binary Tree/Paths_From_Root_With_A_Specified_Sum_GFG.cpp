//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// geeksforgeeks.org/problems/paths-from-root-with-a-specified-sum/1

/*// A Tree node
struct Node
{
    int key;
    struct Node *left, *right;
};*/

class Solution {
  public:
    void solve(Node* root, vector<vector<int>>& result, vector<int> temp, int currSum, int sum){
        if(!root) return;
        
        currSum += root -> key;
        temp.push_back(root -> key);
        
        if(currSum == sum){
            result.push_back(temp);
        }
        
        solve(root -> left, result, temp, currSum, sum);
        solve(root -> right, result, temp, currSum, sum);
    }
    vector<vector<int>> printPaths(Node *root, int sum) {
        vector<vector<int>> result;
        vector<int> temp;
        
        int currSum = 0;
        
        solve(root, result, temp, currSum, sum);
        return result;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
