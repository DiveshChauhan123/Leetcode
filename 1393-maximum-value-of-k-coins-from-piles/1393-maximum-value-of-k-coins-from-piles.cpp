class Solution {
public:
int solve(vector<vector<int>>&piles,int index,int k,vector<vector<int>>&dp){
    if(index>=piles.size())return 0;
    if(dp[index][k]!=-1)return dp[index][k];
    int nottaken=solve(piles,index+1,k,dp);
    int taken=0;
    int sum=0;
    int total=0;
    for(int j=0;j<min(k,(int)piles[index].size());j++){
        sum+=piles[index][j];
        total=max(total,sum+solve(piles,index+1,k-j-1,dp));
    }
    return dp[index][k]=max(nottaken,total);
}
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
       vector<vector<int>>dp(1001,vector<int>(2001,-1));
       return solve(piles,0,k,dp); 
    }
};