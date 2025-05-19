class Solution {
public:
int solve(int n,vector<int>&dp){
    if(n<0)return 0;
    if(dp[n]!=-1)return dp[n];
    int take=solve(n-2,dp);
    int nottake=solve(n-1,dp);
    return dp[n]=take+nottake;
}
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        dp[1]=1;
        dp[0]=1;
        return solve(n,dp);
    }
};