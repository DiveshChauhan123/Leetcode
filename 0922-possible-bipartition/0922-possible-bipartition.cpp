class Solution {
public:
    bool bfs(unordered_map<int, list<int>>& mp, vector<int>& color,int i) {
        queue<int> q;
        q.push(i);
        color[i] = 1;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (auto i : mp[x]) {
                if (color[i] == color[x]) return false;
                else if (color[i] == -1) {
                    q.push(i);
                    color[i] = 1 - color[x];
                }
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, list<int>> mp;
        for (int i = 0; i < dislikes.size(); i++) {
            int a = dislikes[i][0];
            int b = dislikes[i][1];
            mp[a].push_back(b);
            mp[b].push_back(a);  // Adding the reverse edge
        }
        vector<int> color(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                if (!bfs(mp, color,i)) return false;
            }
        }
        return true;
    }
};
