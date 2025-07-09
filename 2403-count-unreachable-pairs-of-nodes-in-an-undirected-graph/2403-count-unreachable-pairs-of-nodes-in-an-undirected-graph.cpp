class Solution {
public:
    void dfs(int node, unordered_map<int, vector<int>> &mp, int &size, vector<int> &visited) {
        visited[node] = 1;
        for (int neigh : mp[node]) {
            if (!visited[neigh]) {
                size++;
                dfs(neigh, mp, size, visited);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < edges.size(); i++) {
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> visited(n, 0);
        long long total_pairs = (long long)n * (n - 1) / 2;
        long long connected_pairs = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int size = 1;
                dfs(i, mp, size, visited);
                connected_pairs += (long long)size * (size - 1) / 2;
            }
        }

        return total_pairs - connected_pairs;
    }
};
