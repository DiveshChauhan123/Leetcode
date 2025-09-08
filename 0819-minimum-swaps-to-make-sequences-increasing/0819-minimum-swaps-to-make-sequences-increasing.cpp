class Solution {
public:
int dp[100001][2];
int solve(vector<int>& nums1, vector<int>& nums2,int index,int swaped){
    if(index>=nums1.size()){
        return 0;
    }
    if(dp[index][swaped]!=-1)return dp[index][swaped];
    int prev1=(index==0?-1:nums1[index-1]);
    int prev2=(index==0?-1:nums2[index-1]);
    if(swaped&&index!=0){
        swap(prev1,prev2);
    }
    int s=INT_MAX;
    int ns=INT_MAX;
    if(nums1[index]==nums2[index]){
        return dp[index][swaped]=solve(nums1,nums2,index+1,swaped);
    }
    if(nums1[index]>prev1 && nums2[index]>prev2){
        s=min(s,solve(nums1,nums2,index+1,0));
        
    }
    if(nums1[index]>prev2 && nums2[index]>prev1){
        s=min(s,1+solve(nums1,nums2,index+1,1));
    }
    return dp[index][swaped]=s;
}
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return solve(nums1,nums2,0,0);
    }
};