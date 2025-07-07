class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int curr_sum=0;
        int result=0;
        for(int i=0;i<nums.size();i++){
            curr_sum+=nums[i];
            result+=mp[curr_sum-goal];
            mp[curr_sum]++;
        }
        return result;
    }
};