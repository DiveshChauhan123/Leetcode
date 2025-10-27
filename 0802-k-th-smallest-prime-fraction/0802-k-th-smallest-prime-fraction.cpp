class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();

        // Min heap storing {fraction_value, numerator_index, denominator_index}
        priority_queue<tuple<double,int,int>, vector<tuple<double,int,int>>, greater<>> pq;

        // Push first element from each column (arr[0]/arr[j])
        for (int j = 1; j < n; j++) {
            pq.push({(double)arr[0] / arr[j], 0, j});
        }

        // Pop smallest k-1 elements
        while (--k) {
            auto [val, i, j] = pq.top();
            pq.pop();

            // Move to next fraction in the same column
            if (i + 1 < j) {
                pq.push({(double)arr[i + 1] / arr[j], i + 1, j});
            }
        }

        auto [val, i, j] = pq.top();
        return {arr[i], arr[j]};
    }
};
