class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<long long, int> mp;

        int limit = cbrt(n);

        // Generate all possible sums
        for (long long a = 1; a <= limit; a++) {
            long long a3 = a * a * a;

            for (long long b = a; b <= limit; b++) {
                long long sum = a3 + b * b * b;

                if (sum > n) break;

                mp[sum]++;
            }
        }

        vector<int> ans;

        for (auto &it : mp) {
            if (it.second >= 2) {
                ans.push_back(it.first);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};