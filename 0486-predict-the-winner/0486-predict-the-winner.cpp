class Solution {
public:
int t[21][21];

    int solve(vector<int>& nums, int s, int e) {
        if (s > e) return 0;
        if (t[s][e] != -1) return t[s][e];

        // Player chooses either start or end and subtracts the opponent's result
        int pickStart = nums[s] - solve(nums, s + 1, e);
        int pickEnd = nums[e] - solve(nums, s, e - 1);

        return t[s][e] = max(pickStart, pickEnd);
    }
    bool predictTheWinner(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(nums,0,nums.size()-1)>=0;
    }
};