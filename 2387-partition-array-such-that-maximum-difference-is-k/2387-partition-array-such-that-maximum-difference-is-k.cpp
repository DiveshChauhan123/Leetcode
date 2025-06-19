class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count=1;
        int n=nums.size();
        int x=nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(x-nums[i]<=k){
                continue;
            }
            count++;
            x=nums[i];
        }
        return count;
    }
};