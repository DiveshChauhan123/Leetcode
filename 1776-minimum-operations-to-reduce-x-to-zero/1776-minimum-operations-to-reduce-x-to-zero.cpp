class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int curr=0;
        int maxLen=INT_MIN;
        for(int l=0,r=0;r<nums.size();r++){
            curr+=nums[r];
            while(l<=r && curr>sum-x)curr-=nums[l++];
            if(curr==sum-x){
                maxLen=max(maxLen,r-l+1);
            }
        }
        return maxLen==INT_MIN?-1:nums.size()-maxLen;
    }
};