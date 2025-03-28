///////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool checkBipartiteDFS(vector<vector<int>>& graph, int curr, vector<int>& color, int currColor) {
        color[curr] = currColor; // color the current node

        // visiting the adjacent node
        for (auto& v : graph[curr]) {

            if (color[v] == color[curr])
                return false;

            if (color[v] == -1) { // node never visited
                int colorOfv = 1 - currColor;
                if (checkBipartiteDFS(graph, v, color, colorOfv) == false)
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v, -1);
        // 0 for red color 
        // 1 for green color

        for (int i = 0; i < v; i++) {
            if (color[i] == -1) {
                if (checkBipartiteDFS(graph, i, color, 1) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
