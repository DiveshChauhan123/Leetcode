class Solution {
public:
int dp[201][201];
int solve(int start,int end){
    if(start>=end)return 0;
    if(dp[start][end]!=-1)return dp[start][end];
    int mini=INT_MAX;
    for(int i=start;i<=end;i++){
        mini=min(mini,i+max(solve(start,i-1),solve(i+1,end)));
    }
    return dp[start][end]=mini;
}
    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(1,n);
    }
};