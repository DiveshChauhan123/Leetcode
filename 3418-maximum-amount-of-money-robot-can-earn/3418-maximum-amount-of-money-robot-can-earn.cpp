class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {

        int n = coins.size();
        int m = coins[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, -1e9)));

        // base case (0,0)
        for(int k = 0; k <= 2; k++){
            if(coins[0][0] >= 0)
                dp[0][0][k] = coins[0][0];
            else {
                if(k > 0) dp[0][0][k] = 0;  // neutralize
                else dp[0][0][k] = coins[0][0];
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0) continue;

                for(int k = 0; k <= 2; k++){

                    int best = -1e9;

                    // from top
                    if(i > 0) best = max(best, dp[i-1][j][k]);

                    // from left
                    if(j > 0) best = max(best, dp[i][j-1][k]);

                    if(best == -1e9) continue;

                    if(coins[i][j] >= 0){
                        dp[i][j][k] = coins[i][j] + best;
                    }
                    else {
                        // option 1: don't neutralize
                        int skip = coins[i][j] + best;

                        // option 2: neutralize
                        int take = -1e9;
                        if(k > 0){
                            int prev = -1e9;
                            if(i > 0) prev = max(prev, dp[i-1][j][k-1]);
                            if(j > 0) prev = max(prev, dp[i][j-1][k-1]);

                            take = prev; // neutralized → 0 added
                        }

                        dp[i][j][k] = max(skip, take);
                    }
                }
            }
        }

        // answer = best among k = 0,1,2
        return max({dp[n-1][m-1][0], dp[n-1][m-1][1], dp[n-1][m-1][2]});
    }
};