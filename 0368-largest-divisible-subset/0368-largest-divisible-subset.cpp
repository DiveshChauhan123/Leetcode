class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>prev(n,-1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<=dp[j]+1){
                        prev[i]=j;
                    }
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        int maxL=0;
        int index=-1;
        for(int i=0;i<n;i++){
            if(maxL<=dp[i]){
                maxL=max(maxL,dp[i]);
                index=i;
            }
        }
        vector<int>result;
        while(index>=0){
            result.push_back(nums[index]);
            index=prev[index];
        }
        return result;
    }
};