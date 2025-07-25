class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=0;
        int mini=INT_MAX;
        long long sum=0;
        while(j<nums.size()){
            sum+=nums[j];
            while(sum>=target){
                mini=min(j-i+1,mini);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return mini==INT_MAX?0:mini;
    }
};