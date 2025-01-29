class Solution {
public:
    int n;
    int dp[2501][2501]; // for memoization 
    int solve(vector<int>& nums, int i, int p){
        if(i >= n) return 0;

        // check it is already evaluated or not in memoization
        if(p!=-1 && dp[i][p] != -1) return dp[i][p];

        // when take it index value
        int take = 0;
        // check those value is greater than the previous stored value 
        if(p==-1 || nums[i] > nums[p]){
            take = 1 + solve(nums, i+1, i);
        }

        // not take that value skip
        int skip = solve(nums, i+1, p);
        
        // when p = -1 then do not try to store in memoize array or access it
        if(p != -1) dp[i][p] = max(take, skip);

        return max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        // fill memoize array value by default -1
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, -1);
    }
};