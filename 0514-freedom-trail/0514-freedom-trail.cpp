class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        unordered_map<char, vector<int>> pos;
        
        // Store all indices of each character in the ring
        for (int i = 0; i < n; i++) {
            pos[ring[i]].push_back(i);
        }
        
        int m = key.size();
        vector<vector<int>> dp(m + 1, vector<int>(n, INT_MAX));
        
        // Base case: 0 steps needed when key is finished
        for (int j = 0; j < n; j++) dp[m][j] = 0;
        
        // Fill DP from back to front
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) { // current ring position
                for (int k : pos[key[i]]) { // possible next position
                    int dist = abs(j - k);
                    dist = min(dist, n - dist); // circular distance
                    dp[i][j] = min(dp[i][j], dist + 1 + dp[i + 1][k]);
                }
            }
        }
        
        return dp[0][0]; 
    }
};
