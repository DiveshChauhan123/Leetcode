class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;

        // Create an array of unordered_maps to store differences for each index
        unordered_map<long long, long long> mp[n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long diff = 1LL * nums[i] - nums[j];
                
                // Find the count of arithmetic subsequences ending at j with the difference 'diff'
                long long count = mp[j].count(diff) ? mp[j][diff] : 0;

                // Store or update the difference count for the current index i
                mp[i][diff] += count + 1;

                // Add the count of subsequences found so far to the result
                result += count;
            }
        }
        return result;
    }
};
