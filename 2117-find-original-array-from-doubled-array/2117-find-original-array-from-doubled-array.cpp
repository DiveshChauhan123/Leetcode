class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2 != 0) return {}; // must be even size

        sort(changed.begin(), changed.end()); // sort to process smaller elements first

        unordered_map<int, int> count;
        for (int x : changed) count[x]++;

        vector<int> original;

        for (int x : changed) {
            if (count[x] == 0) continue;

            // For zero: need pairs like [0, 0]
            if (x == 0) {
                if (count[0] < 2) return {};
                count[0] -= 2;
                original.push_back(0);
            } else if (count[x * 2] > 0) {
                count[x]--;
                count[x * 2]--;
                original.push_back(x);
            } else {
                return {};
            }
        }

        return original;
    }
};
