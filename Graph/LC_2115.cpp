//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Brute Force: O(n^2).
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        vector<string> result;
        unordered_set<string> st(begin(supplies), end(supplies));
        vector<bool> cooked(n, false);

        int count = n;

        while (count--) {

            for (int j = 0; j < n; j++) {
                if (cooked[j])
                    continue;

                bool canBeCooked = true;
                for (int k = 0; k < ingredients[j].size(); k++) {
                    if (!st.count(ingredients[j][k])) {
                        canBeCooked = false;
                        break;
                    }
                }

                if (canBeCooked) {
                    cooked[j] = true;
                    result.push_back(recipes[j]);
                    st.insert(recipes[j]);
                }
            }
        }
        return result;
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Using Topological Sort: Kahn's Algorithm
class Solution {
public:
     vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_set<string> st(begin(supplies), end(supplies));
        vector<int> inDegree(n, 0);
        unordered_map<string, vector<int>> adj;

        for (int i = 0; i < n; i++) {
            for (string& ing : ingredients[i]) {
                if (!st.count(ing)) {
                    adj[ing].push_back(i);
                    inDegree[i]++;
                }
            }
        }

        queue<int> que;
        vector<string> result;

        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                que.push(i);
            }
        }

        while (!que.empty()) {
            int u = que.front();
            string recipe = recipes[u];
            result.push_back(recipe);
            que.pop();

            for (int& idx : adj[recipe]) {
                inDegree[idx]--;

                if (inDegree[idx] == 0) {
                    que.push(idx);
                }
            }
        }
        return result;
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////

