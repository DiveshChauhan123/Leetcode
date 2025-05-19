class Solution {
public:
int solve(vector<int>&prices,int n,vector<vector<int>>&dp,int day,int x){
    if(day>=n)return 0;
    if(dp[day][x]!=-1)return dp[day][x];
    if(x){
        int take=solve(prices,n,dp,day+1,0)-prices[day];
        int nottake=solve(prices,n,dp,day+1,1);
        dp[day][x]=max(dp[day][x],max(take,nottake));
    }
    else{
        int take=solve(prices,n,dp,day+2,1)+prices[day];
        int nottake=solve(prices,n,dp,day+1,0);
        dp[day][x]=max(dp[day][x],max(take,nottake));
    }
    return dp[day][x];
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(5001,vector<int>(2,-1));
        return solve(prices,n,dp,0,1);
    }
};