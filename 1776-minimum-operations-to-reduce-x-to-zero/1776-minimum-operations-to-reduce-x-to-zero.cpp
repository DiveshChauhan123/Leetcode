class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int curr=0;
        int maxLen=INT_MIN;
        int l=0,r=0;
        while(r<nums.size()){
            curr+=nums[r];
            while(l<=r && curr>sum-x){
                curr-=nums[l];
                l++;
            }
            if(curr==sum-x){
                maxLen=max(maxLen,r-l+1);
            }
            r++;
        }
        return maxLen==INT_MIN?-1:nums.size()-maxLen;
    }
};