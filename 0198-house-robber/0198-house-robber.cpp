class Solution {
public:
int solve(int n,vector<int>&dp,vector<int>&nums){
    if(nums.size()<=n)return 0;
    if(dp[n]!=-1)return dp[n];
    int take=nums[n]+solve(n+2,dp,nums);
    int skip=solve(n+1,dp,nums);
    return dp[n]=max(take,skip);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(0,dp,nums);
    }
};