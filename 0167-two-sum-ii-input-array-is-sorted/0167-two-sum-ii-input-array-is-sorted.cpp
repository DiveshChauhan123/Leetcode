class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); i++) {
            int rem = target - numbers[i];
            auto it = lower_bound(numbers.begin() + i + 1, numbers.end(), rem);

            if (it != numbers.end() && numbers[i] + *it == target) {
                int idx = it - numbers.begin();
                return {i + 1, idx + 1}; // 1-based index
            }
        }
        return {};
    }
};
