class Solution {
public:
    const int MOD = 1e9 + 7;

    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> rightFreq, leftFreq;
        
        // Fill initial rightFreq with all elements
        for (int num : nums) {
            rightFreq[num]++;
        }

        int result = 0;

        for (int j = 0; j < n; j++) {
            rightFreq[nums[j]]--;  // nums[j] is now being considered as middle

            int leftCount = leftFreq[2 * nums[j]];
            int rightCount = rightFreq[2 * nums[j]];

            result = (result + 1LL * leftCount * rightCount % MOD) % MOD;

            leftFreq[nums[j]]++;  // Move nums[j] to left side
        }

        return result;
    }
};
