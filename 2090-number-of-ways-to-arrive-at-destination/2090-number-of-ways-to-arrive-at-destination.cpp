class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long MOD = 1e9 + 7;
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> pq;
        pq.push({0, 0});
        unordered_map<long long, list<pair<long long, long long>>> mp;

        for (long long i = 0; i < (long long)roads.size(); i++) {
            long long u = roads[i][0];
            long long v = roads[i][1];
            long long weight = roads[i][2];
            mp[u].push_back({v, weight});
            mp[v].push_back({u, weight});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;

        while (!pq.empty()) {
            long long currdist = pq.top().first;
            long long node = pq.top().second;
            pq.pop();
            if (currdist > dist[node]) continue;

            for (auto neigh : mp[node]) {
                long long u = neigh.first;
                long long w = neigh.second;
                if (dist[u] > dist[node] + w) {
                    dist[u] = dist[node] + w;
                    ways[u] = ways[node];
                    pq.push({dist[u], u});
                } else if (dist[u] == dist[node] + w) {
                    ways[u] = (ways[node] + ways[u]) % MOD;
                }
            }
        }
        return (int)ways[n - 1];
    }
};
