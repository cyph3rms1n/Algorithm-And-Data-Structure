/////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    void DFS(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0' ||
            visited[i][j])
            return;

        visited[i][j] = true;

        DFS(grid, visited, i + 1, j);
        DFS(grid, visited, i - 1, j);
        DFS(grid, visited, i, j + 1);
        DFS(grid, visited, i, j - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        int count = 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    DFS(grid, visited, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////
