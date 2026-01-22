class Solution {
public:
int t[101]; //  t[i] gives us max value that robbed amount that robber will take home wiht him
int solve(int index,int size,vector<int>&nums){
    if(index>=size)return 0;
    //base case
    if(t[index]!=-1)return t[index];
    int take=nums[index]+solve(index+2,size,nums);
    int nottake=solve(index+1,size,nums);
    return t[index]=max(take,nottake);
}
    int rob(vector<int>& nums) {
        if(nums.size()==0)return 0;
        if(nums.size()==1)return nums[0];
        memset(t,-1,sizeof(t));
        int n=nums.size();
        int a=solve(0,n-1,nums);
        memset(t,-1,sizeof(t));
        int b=solve(1,n,nums);
        return max(a,b);
    }
};