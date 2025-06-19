class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> diagonals;
        int maxKey = 0;

        // Group elements by i + j
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                diagonals[i + j].push_back(nums[i][j]);
                maxKey = max(maxKey, i + j);
            }
        }

        // Traverse diagonals in order and reverse each group
        vector<int> result;
        for (int k = 0; k <= maxKey; k++) {
            auto& vec = diagonals[k];
            reverse(vec.begin(), vec.end()); // Reverse to match top-to-bottom diagonal traversal
            result.insert(result.end(), vec.begin(), vec.end());
        }

        return result;
    }
};
