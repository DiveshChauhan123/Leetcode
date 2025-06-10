class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        long long count=0;
        long long x=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)x++;
            else{
                count+=(x*(x+1))/2;
                x=0;
            }
        }
        if(x!=0){
            count+=(x*(x+1))/2;
        }
        return count;
    }
};