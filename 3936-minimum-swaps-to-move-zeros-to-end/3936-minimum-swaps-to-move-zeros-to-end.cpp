class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int zero = 0;

        for (int x : nums) {
            if (x == 0) zero++;
        }
        int y=zero;
        for (int i = (int)nums.size() - 1; i >= (int)nums.size() - zero; i--) {
            if (nums[i] == 0) y--;
        }

        return y;
    }
};