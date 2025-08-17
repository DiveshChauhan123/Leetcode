class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0,j=0,count=0;
        while(i<n && j<n){
            if(nums[j]>nums[i]){
                i++;
                count++;
            }
            j++;
        }
        return count;
    }
};