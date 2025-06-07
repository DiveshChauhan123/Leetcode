class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int currmax=nums[0],currmin=nums[0],maxsum=nums[0],minsum=nums[0];
        int sum=accumulate(nums.begin(),nums.end(),0);
        int s=0;
        for(int i=1;i<n;i++){
            //kadane for maxsum 
            currmax=max(currmax,0)+nums[i];
            maxsum=max(currmax,maxsum);
            //kadane for minsum
            currmin=min(currmin,0)+nums[i];
            minsum=min(currmin,minsum);
            
        }
        if(maxsum<=0)return maxsum;
        return int(max(sum-minsum,maxsum));
    }
};