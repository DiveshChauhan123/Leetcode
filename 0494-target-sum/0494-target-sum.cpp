class Solution {
public:
int dp[2001][21];
int solve(vector<int>&nums,int target,int index,int value){
    if(index>=nums.size()){
        if(value==target)return 1;
        else{
            return 0;
        }
    }
    if(dp[value+1000][index]!=-1)return dp[value+1000][index];
    int plus=solve(nums,target,index+1,nums[index]+value);
    int minus=solve(nums,target,index+1,value-nums[index]);
    return dp[value+1000][index]=plus+minus;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,target,0,0);
    }
};