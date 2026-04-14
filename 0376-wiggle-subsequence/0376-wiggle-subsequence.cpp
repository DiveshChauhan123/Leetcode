class Solution {
public:
int t[1001][2001];
    int solve(vector<int>& nums, int i, int prevDiff) {
        if (i >= nums.size() - 1) return 1;
        if(t[i][1000+prevDiff]!=-1)return t[i][1000+prevDiff];
        int notTake = solve(nums, i + 1, prevDiff);

        int take = 0;
        int diff = nums[i + 1] - nums[i];

        if (diff != 0 && (prevDiff == 0 || (diff > 0 && prevDiff < 0) || (diff < 0 && prevDiff > 0))) {
            take = 1 + solve(nums, i + 1, diff);
        }

        return t[i][prevDiff+1000]=max(take, notTake);
    }

    int wiggleMaxLength(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        if (nums.size() <= 1) return nums.size();
        return solve(nums, 0, 0);
    }
};