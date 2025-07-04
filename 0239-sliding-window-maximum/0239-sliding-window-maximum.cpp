class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> q;  // Fix: 'deque' instead of 'dequeue'

        for (int i = 0; i < nums.size(); i++) {
            // Remove indices out of current window
            if (!q.empty() && q.front() <= i - k) {
                q.pop_front();
            }

            // Maintain decreasing order in deque
            while (!q.empty() && nums[i] > nums[q.back()]) {
                q.pop_back();
            }

            q.push_back(i);

            // Record max for each window
            if (i >= k - 1) {
                result.push_back(nums[q.front()]);
            }
        }

        return result;
    }
};
