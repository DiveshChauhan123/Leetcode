class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0,j=0;
        if(k<=1)return 0;
        long long product=1;
        int result=0;
        while(j<nums.size()){
            product*=nums[j];
            while(product>=k){
                product/=1LL*nums[i];
                i++;
            }
            result+=j-i+1;
            j++;
        }
        return result;
    }
};