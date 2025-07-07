class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long count=0;
        int count_max=0;
        int i=0,j=0;
        int maxi=*max_element(nums.begin(),nums.end());
        while(j<nums.size()){
            if(nums[j]==maxi)count_max++;
            while(count_max>=k){
                count+=(nums.size()-j);
                if(maxi==nums[i])count_max--;
                i++;
            }
            j++;
        }
        return count;
    }
};