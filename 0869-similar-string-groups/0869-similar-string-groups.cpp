class Solution {
public:
    // Check if two strings differ at exactly two positions
    bool isSimilar(string s, string p) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != p[i]) count++;
        }
        return count == 2 || count == 0; // 0 if same, 2 if swappable
    }

    // DFS to mark all connected nodes
    void dfs(int i, unordered_map<int, vector<int>>& mp, vector<int>& visited) {
        visited[i] = true;
        for (int neigh : mp[i]) {
            if (!visited[neigh]) {
                dfs(neigh, mp, visited);
            }
        }
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<int> visited(n, 0);
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isSimilar(strs[i], strs[j])) {
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                result++;
                dfs(i, mp, visited);
            }
        }

        return result;
    }
};
