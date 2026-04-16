class Solution {
public:
int t[10001][201];
int solve(vector<int>&nums,int i,int target){
    if(target==0)return true;
    if(target<0)return false;
    if(i>=nums.size())return false;
    if(t[target][i]!=-1){
        return t[target][i]==1?true:false;
    }
    bool take=solve(nums,i+1,target-nums[i]);
    bool nottake=solve(nums,i+1,target);
    return t[target][i]=take || nottake;
}
    bool canPartition(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1)return false;
        return solve(nums,0,sum/2);
    }
};