class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0)ans.push_back(nums[i]);
        }
        for(int i=0;i<n;i++){
            if(nums[i]%2!=0)ans.push_back(nums[i]);
        }
        return ans;
    }
};