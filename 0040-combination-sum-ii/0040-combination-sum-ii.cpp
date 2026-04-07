class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;

    void solve(int idx, vector<int>& candidates, int target) {
        if(target == 0){
            result.push_back(temp);
            return;
        }

        for(int i = idx; i < candidates.size(); i++){
            // skip duplicates
            if(i > idx && candidates[i] == candidates[i-1]) continue;

            // if element exceeds target → stop
            if(candidates[i] > target) break;

            temp.push_back(candidates[i]);
            solve(i + 1, candidates, target - candidates[i]);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, target);
        return result;
    }
};