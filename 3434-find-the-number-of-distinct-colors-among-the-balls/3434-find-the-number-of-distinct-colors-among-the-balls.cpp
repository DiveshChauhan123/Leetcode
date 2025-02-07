#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ans; // Store only used indices
        unordered_map<int, int> mp;  // Frequency map
        vector<int> nums;
        int count = 0;

        for (auto& q : queries) {
            int u = q[0], v = q[1];

            // Decrease frequency of previous value (if any)
            if (ans.count(u)) {
                int old_val = ans[u];
                mp[old_val]--;
                if (mp[old_val] == 0) {
                    count--; 
                    mp.erase(old_val); // Free memory
                }
            }

            // Assign new value
            ans[u] = v;
            if (++mp[v] == 1) { // If v was not present before, increase count
                count++;
            }

            nums.push_back(count);
        }
        return nums;
    }
};
