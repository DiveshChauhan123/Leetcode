class Solution {
public:
    int findValueOfPartition(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int res=INT_MAX,n=nums.size();
        for(int i=0;i<n-1;i++)
           res=min(res,nums[i+1]-nums[i]);
        return res;   
    }
};