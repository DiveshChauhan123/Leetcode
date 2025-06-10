class Solution {
public:
int n;
int dp[50001][2];
int solve(vector<int>& prices, int fee,int day,int x){
    if(day>=n)return 0;
    if(dp[day][x]!=-1)return dp[day][x];
    if(x){
        int take=solve(prices,fee,day+1,0)-prices[day]-fee;
        int nottake=solve(prices,fee,day+1,1);
        dp[day][x]=max(dp[day][x],max(take,nottake));
    }
    else{
        int take=solve(prices,fee,day+1,1)+prices[day];
        int nottake=solve(prices,fee,day+1,0);
        dp[day][x]=max(dp[day][x],max(take,nottake));
    }
    return dp[day][x];
}
    int maxProfit(vector<int>& prices, int fee) {
        n=prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(prices,fee,0,1);
    }
};