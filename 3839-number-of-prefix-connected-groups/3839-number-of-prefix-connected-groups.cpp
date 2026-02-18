class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string, int> cnt;

        for (auto &w : words) {
            if ((int)w.size() < k) continue;   // ignore short words
            string pref = w.substr(0, k);
            cnt[pref]++;
        }

        int groups = 0;
        for (auto &it : cnt) {
            if (it.second >= 2) {
                groups++;
            }
        }

        return groups;
    }
};