class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        int n = nums1.size(), m = nums2.size();
        if (n == 0 || m == 0) return result;

        // Min-heap: {sum, index in nums1, index in nums2}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        
        for (int i = 0; i < n && i < k; ++i)
            pq.push({nums1[i] + nums2[0], i, 0});

        while (k-- > 0 && !pq.empty()) {
            auto curr = pq.top(); pq.pop();
            int i = curr[1], j = curr[2];
            result.push_back({nums1[i], nums2[j]});

            
            if (j + 1 < m)
                pq.push({nums1[i] + nums2[j + 1], i, j + 1});
        }
        return result;
    }
};
