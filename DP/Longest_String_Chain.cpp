// LC: 1048. Longest String Chain
///////////////////////////////////////////////////////////////////////////////////////////
// Approach 1: Recursion + Memorization
// TC: O(n^2 * k)  SC: o(n^2)

class Solution {
public:
    int n;
    int t[1001][1001];

    bool isPred(string& word1, string& word2) { // o(k)
        int M = word1.length();
        int N = word2.length();

        if (M >= N || N - M != 1) {
            return false;
        }

        int i = 0, j = 0;

        while (i < M && j < N) {
            if (word1[i] == word2[j]) {
                i++;
            }
            j++;
        }
        return i == M;
    }

    static bool myFunction(string& word1, string& word2) {
        return word1.length() < word2.length();
    }

    int lis(int i, int p, vector<string>& words) {
        if (i >= n)
            return 0;

        if (p != -1 && t[i][p] != -1)
            return t[i][p];

        int take = 0, skip = 0;

        if (p == -1 || isPred(words[p], words[i])) {
            take = 1 + lis(i + 1, i, words);
        }
        skip = lis(i + 1, p, words);

        if (p !=-1) {
            return t[i][p] = max(take, skip);
        }

        return max(take, skip);
    }
    int longestStrChain(vector<string>& words) {
        n = words.size();
        memset(t, -1, sizeof(t));
        sort(begin(words), end(words), myFunction);

        return lis(0, -1, words);
    }
};
///////////////////////////////////////////////////////////////////////////////////////////
// Approach 1: Bottom - Up
// TC: O(n^2 * k)  SC: o(n)

class Solution {
public:
    int n;
    int t[1001][1001];

    bool isPred(string& word1, string& word2) { // o(k)
        int M = word1.length();
        int N = word2.length();

        if (M >= N || N - M != 1) {
            return false;
        }

        int i = 0, j = 0;

        while (i < M && j < N) {
            if (word1[i] == word2[j]) {
                i++;
            }
            j++;
        }
        return i == M;
    }

    static bool myFunction(string& word1, string& word2) {
        return word1.length() < word2.length();
    }

    int longestStrChain(vector<string>& words) {
        n = words.size();
        sort(begin(words), end(words), myFunction);

        vector<int> t(n, 1);

        int maxLength = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (isPred(words[j], words[i])) {
                    t[i] = max(t[i], t[j] + 1);
                    maxLength = max(maxLength, t[i]);
                }
            }
        }
        return maxLength;
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////
