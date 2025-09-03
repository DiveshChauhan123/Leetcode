class Solution {
public:
    void dijkstra(int s, vector<int>& ans, unordered_map<int, vector<pair<int,int>>>& mp) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        ans[s] = 0;
        pq.push({0, s}); // (distance, node)
        
        while (!pq.empty()) {
            auto [dist, u] = pq.top();
            pq.pop();
            
            if (dist > ans[u]) continue;
            
            for (auto [node, wt] : mp[u]) {
                if (wt + ans[u] < ans[node]) {
                    ans[node] = wt + ans[u];
                    pq.push({ans[node], node});
                }
            }
        }
    }

    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int,int>>> mp;
        vector<int> source(n, INT_MAX);
        vector<int> destination(n, INT_MAX);

        for (auto& e : edges) {
            mp[e[0]].push_back({e[1], e[2]});
            mp[e[1]].push_back({e[0], e[2]});
        }

        dijkstra(0, source, mp);
        dijkstra(n-1, destination, mp);

        vector<bool> ans;
        for (auto& e : edges) {
            int u = e[0], v = e[1], wt = e[2];
            if (source[n-1] != INT_MAX &&
    destination[u] != INT_MAX &&
    destination[v] != INT_MAX &&
    source[u] != INT_MAX &&
    source[v] != INT_MAX &&
    ((source[u] + wt + destination[v] == source[n-1]) ||
     (source[v] + wt + destination[u] == source[n-1]))) {
    ans.push_back(true);
} else {
    ans.push_back(false);
}

        }
        return ans;
    }
};
