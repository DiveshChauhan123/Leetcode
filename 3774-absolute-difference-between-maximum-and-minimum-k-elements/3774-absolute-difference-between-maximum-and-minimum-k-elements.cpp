class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>nums.size())return 0;
        sort(nums.begin(),nums.end());
        int maxi=0;
        int mini=0;
        for(int i=0;i<k;i++)mini+=nums[i];
        for(int i=n-1;i>=n-k;i--)maxi+=nums[i];
        return maxi-mini;
    }
};