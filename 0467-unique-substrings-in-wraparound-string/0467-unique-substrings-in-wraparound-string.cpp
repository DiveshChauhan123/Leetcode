class Solution {
public:
    int findSubstringInWraproundString(string s) {
        vector<int> maxLen(26, 0);

        int currLen = 0;

        for (int i = 0; i < s.size(); i++) {
            if (i > 0 && (s[i] - s[i - 1] + 26) % 26 == 1) {
                currLen++;
            } else {
                currLen = 1;
            }

            int idx = s[i] - 'a';
            maxLen[idx] = max(maxLen[idx], currLen);
        }

        return accumulate(maxLen.begin(), maxLen.end(), 0);
    }
};