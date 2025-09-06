class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // build adjacency list
        vector<vector<int>> adj(n+1);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // BFS queue
        queue<pair<int,int>> q; // {node, time}
        q.push({1,0});

        // store arrival times
        vector<vector<int>> dist(n+1);
        dist[1].push_back(0);

        while (!q.empty()) {
            auto [u, t] = q.front(); q.pop();

            for (int v : adj[u]) {
                int newTime = t;
                if ((newTime / change) % 2 == 1) {
                    newTime = (newTime / change + 1) * change;
                }
                newTime += time;

                if (dist[v].empty() || (dist[v].size()==1 && dist[v][0] != newTime)) {
                    dist[v].push_back(newTime);
                    sort(dist[v].begin(), dist[v].end());
                    if (dist[v].size() > 2) dist[v].pop_back();
                    q.push({v, newTime});
                }

                if (v == n && dist[v].size() == 2) {
                    return dist[v][1]; 
                }
            }
        }

        return -1; 
    }
};
