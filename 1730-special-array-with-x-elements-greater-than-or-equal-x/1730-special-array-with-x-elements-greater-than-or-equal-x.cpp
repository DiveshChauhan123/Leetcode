class Solution {
public:
    bool possible(vector<int>& nums, int mid) {
        int count = 0;
        for (int num : nums) {
            if (num >= mid) count++;
        }
        return count == mid;
    }

    int specialArray(vector<int>& nums) {
        int s = 0;
        int e = nums.size();
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (possible(nums, mid)) {
                return mid;
            } else {
                int count = 0;
                for (int num : nums) {
                    if (num >= mid) count++;
                }
                if (count > mid) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
        }
        return -1;
    }
};
