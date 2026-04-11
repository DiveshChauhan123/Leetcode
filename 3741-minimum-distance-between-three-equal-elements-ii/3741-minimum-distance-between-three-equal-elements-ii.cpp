class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        // Store indices
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        // Check each value
        for (auto &it : mp) {
            vector<int> &v = it.second;

            if (v.size() < 3) continue;

            // Check consecutive triplets
            for (int i = 0; i + 2 < v.size(); i++) {
                ans = min(ans, v[i + 2] - v[i]);
            }
        }

        return (ans == INT_MAX ? -1 : 2*ans);
    }
};