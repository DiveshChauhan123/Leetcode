class Solution {
public:
int t[101];
int solve(int index,vector<int>&nums){
    if(index>=nums.size())return 0;
    if(t[index]!=-1)return t[index];
    int nottake=solve(index+1,nums);
    int take=nums[index]+solve(index+2,nums);
    return t[index]=max(nottake,take);
}
    int rob(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(0,nums);
    }
};