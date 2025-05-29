class Solution {
public:
    int n;

    int solve(vector<int>& nums, int op, vector<int>& visited, map<vector<int>, int>& mp) {
        if (mp.find(visited) != mp.end()) return mp[visited];

        int maxscore = 0;
        for (int i = 0; i < n - 1; i++) {
            if (visited[i]) continue;
            for (int j = i + 1; j < n; j++) {
                if (visited[j]) continue;
                visited[i] = 1;
                visited[j] = 1;
                int curr = op * __gcd(nums[i], nums[j]);
                int next = solve(nums, op + 1, visited, mp);
                maxscore = max(maxscore, curr + next);
                visited[i] = 0;
                visited[j] = 0;
            }
        }
        return mp[visited] = maxscore;
    }

    int maxScore(vector<int>& nums) {
        vector<int> visited(nums.size(), 0);
        map<vector<int>, int> mp;  // ✅ fixed
        n = nums.size();
        return solve(nums, 1, visited, mp);
    }
};
