class Solution {
public:
    bool canForm(vector<int>& nums, int p, int mid) {
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] <= mid) {
                count++;
                i++; // skip next to avoid overlapping
            }
        }
        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums.front(), ans = 0;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (canForm(nums, p, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
