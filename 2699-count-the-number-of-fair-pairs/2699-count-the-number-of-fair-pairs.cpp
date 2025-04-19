class Solution {
public:
//brute force approach
//T.C:O(n^2)
//S.C:O(1)
// it will give tle we have to optimize the solution
    // long long countFairPairs(vector<int>& nums, int lower, int upper) {
    //     int n=nums.size();
    //     int count=0;
    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++){
    //             if(nums[i]+nums[j]<=upper && nums[i]+nums[j]>=lower){
    //                 count++;
    //             }
    //         }
    //     }
    //     return count;
    // }
//Optimize approach
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        long long count=0;
        sort(nums.begin(),nums.end());
        int s=0,e=n-1;
        for (int i = 0; i < n; ++i) {
        int l = lower - nums[i];
        int r = upper - nums[i];

        auto left = std::lower_bound(nums.begin() + i + 1, nums.end(), l);
        auto right = std::upper_bound(nums.begin() + i + 1, nums.end(), r);

        count += 1LL*(right - left);
    }

    return count;
    }
};