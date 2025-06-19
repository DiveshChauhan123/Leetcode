class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> temp(nums.begin(), nums.end());
        vector<int> s(temp.begin(), temp.end());
        sort(s.begin(), s.end());  // sort the deduplicated vector

        int count = INT_MAX;
        for (int i = 0; i < s.size(); i++) {
            int l = s[i];
            int r = s[i] + n - 1;
            int x = upper_bound(s.begin(), s.end(), r) - s.begin();
            int within_range = x - i;
            int out_range = n - within_range;
            count = min(count, out_range);
        }
        return count;
    }
};
