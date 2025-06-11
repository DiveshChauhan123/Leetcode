class Solution {
public:
int n;
int t[1001][10003];
int solve(vector<int>& nums,int i,int diff){
    if(i>=n){
        if(diff==0)return 0;
        return INT_MIN;
    }
    if(t[i][diff+5001]!=-1)return t[i][diff+5001];
    int nothing=solve(nums,i+1,diff);
    int l=nums[i]+solve(nums,i+1,diff+nums[i]);
    int r=nums[i]+solve(nums,i+1,diff-nums[i]);
    return t[i][diff+5001]=max({l,r,nothing});
}
    int tallestBillboard(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        n=nums.size();
        return solve(nums,0,0)/2;
    }
};