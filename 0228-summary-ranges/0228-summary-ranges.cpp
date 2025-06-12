class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.empty()) return ans;

        int a = nums[0], b = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                b = nums[i];
            } else {
                if (a == b)
                    ans.push_back(to_string(a));
                else
                    ans.push_back(to_string(a) + "->" + to_string(b));
                
                a = b = nums[i];
            }
        }

        // Last segment
        if (a == b)
            ans.push_back(to_string(a));
        else
            ans.push_back(to_string(a) + "->" + to_string(b));

        return ans;
    }
};
