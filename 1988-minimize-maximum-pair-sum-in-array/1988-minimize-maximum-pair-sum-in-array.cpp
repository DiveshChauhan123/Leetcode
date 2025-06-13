class Solution {
public:
    int minPairSum(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int s=0;
       int e=nums.size()-1;
       int maxi=INT_MIN;
       while(s<e){
        maxi=max(nums[s]+nums[e],maxi);
        s++;
        e--;
       }
       return maxi;
    }
};