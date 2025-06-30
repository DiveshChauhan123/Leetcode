class Solution {
public:
int n;
int dp[100001][2][3];
int solve(vector<int>&prices,int index,int transactions,int to_do){
    if(index>=n)return 0;
    if(transactions==0)return 0;
    if(dp[index][to_do][transactions]!=-1)return dp[index][to_do][transactions];
    int take=0;
    int skip=solve(prices,index+1,transactions,to_do);
    if(to_do){
        take=solve(prices,index+1,transactions,0)-prices[index];
    }
    else{
        take=prices[index]+solve(prices,index+1,transactions-1,1);
    }
    return dp[index][to_do][transactions]=max(skip,take);
}
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,2,1);
    }
};