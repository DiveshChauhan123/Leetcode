class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        
        unordered_map<int, list<int>> adj;
        vector<int> degree(n, 0);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }

        vector<int> result;
        while (!q.empty()) {
            int size = q.size();
            result.clear();
            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();
                result.push_back(node);
                for (const auto& neighbor : adj[node]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }

        return result;
    }
};
