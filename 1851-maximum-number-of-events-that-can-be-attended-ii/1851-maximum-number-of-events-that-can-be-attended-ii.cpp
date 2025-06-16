class Solution {
public:
    int n;
    vector<vector<int>> dp;

    // Binary search to find the next non-overlapping event
    int findNext(vector<vector<int>>& events, int currEnd, int startIndex) {
        int low = startIndex, high = events.size() - 1;
        int nextIndex = events.size();
        while (low <= high) {
            int mid = (low + high) / 2;
            if (events[mid][0] > currEnd) {
                nextIndex = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return nextIndex;
    }

    int solve(int index, int k, vector<vector<int>>& events) {
        if (index == n || k == 0) return 0;
        if (dp[index][k] != -1) return dp[index][k];

        // Option 1: Skip current event
        int skip = solve(index + 1, k, events);

        // Option 2: Take current event
        int nextIndex = findNext(events, events[index][1], index + 1);
        int take = events[index][2] + solve(nextIndex, k - 1, events);

        return dp[index][k] = max(skip, take);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end()); // sort by start time
        n = events.size();
        dp.assign(n + 1, vector<int>(k + 1, -1));
        return solve(0, k, events);
    }
};
