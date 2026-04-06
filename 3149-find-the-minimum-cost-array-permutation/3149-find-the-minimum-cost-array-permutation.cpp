class Solution {
public:
    int mini = INT_MAX;
    vector<int> resultpre;

    void solve(vector<int>& nums, int score, vector<int>& prem, vector<int>& visited) {
        int n = nums.size();
        if(score>mini)return;
        if (prem.size() == n) {
            score += abs(prem.back() - nums[prem[0]]);
            if (mini > score) {
                mini = score;
                resultpre = prem;
            }
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = 1;
                prem.push_back(i);

                int added = 0;
                if (prem.size() > 1) {
                    int sz = prem.size();
                    added = abs(prem[sz - 2] - nums[prem[sz - 1]]);
                }

                solve(nums, score + added, prem, visited);

                prem.pop_back();
                visited[i] = 0;
            }
        }
    }

    vector<int> findPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<int> visited(n, 0);

        vector<int> prem = {0};
        visited[0] = 1; // IMPORTANT

        solve(nums, 0, prem, visited);
        return resultpre;
    }
};