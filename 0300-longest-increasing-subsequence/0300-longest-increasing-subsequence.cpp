class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(nums.size(),1);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                int skip=dp[i];
                int take=0;
                if(nums[i]>nums[j]){
                    take=dp[j]+1;
                }
                dp[i]=max(skip,take);
            }
        }
        int l=0;
        for(int i=0;i<n;i++){
            l=max(l,dp[i]);
        }
        return l;
    }
};