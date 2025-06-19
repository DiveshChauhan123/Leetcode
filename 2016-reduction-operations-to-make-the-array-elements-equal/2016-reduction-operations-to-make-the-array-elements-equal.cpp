class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int count=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)mp[nums[i]]++;
        for(int i=n-1;i>0;i--){
            if(nums[i]==nums[i-1])continue;
            count+=mp[nums[i]];
            mp[nums[i-1]]+=mp[nums[i]];
        }
        return count;
    }
};