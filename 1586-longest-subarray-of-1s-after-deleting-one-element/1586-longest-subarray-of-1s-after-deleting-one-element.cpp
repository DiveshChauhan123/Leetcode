class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0;
        int j=0;
        int count=0;
        int maxval=-1;
        int noofzeros=0;
        while(j<nums.size()){
            if(nums[j]==0)count++;
            if(count>1){
                if(nums[i]==0)count--;
                i++;
            }
            if(count==1){
                maxval=max(maxval,j-i+1-count);
            }
            else if(count==0){
                maxval=max(maxval,j-i);
            }
            j++;
        }
        return maxval;
    }
};