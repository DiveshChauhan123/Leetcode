class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int, int>> jobs(n);
        for (int i = 0; i < n; i++) {
            jobs[i] = {difficulty[i], profit[i]};
        }

        sort(jobs.begin(), jobs.end());

        // Build max profit up to each difficulty
        vector<int> maxProfit;
        vector<int> diff;
        int currMax = 0;
        for (int i = 0; i < n; ++i) {
            currMax = max(currMax, jobs[i].second);
            diff.push_back(jobs[i].first);
            maxProfit.push_back(currMax);
        }

        // Assign jobs
        int total_profit = 0;
        for (int w : worker) {
            int idx = upper_bound(diff.begin(), diff.end(), w) - diff.begin() - 1;
            if (idx >= 0) total_profit += maxProfit[idx];
        }

        return total_profit;
    }
};
