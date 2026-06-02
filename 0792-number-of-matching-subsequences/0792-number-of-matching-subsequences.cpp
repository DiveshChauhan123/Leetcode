class Solution {
public:
    unordered_map<string,bool> dp;

    bool isSubsequence(string &s, string &word) {

        if(dp.count(word))
            return dp[word];

        int i = 0, j = 0;

        while(i < s.size() && j < word.size()) {
            if(s[i] == word[j])
                j++;
            i++;
        }

        return dp[word] = (j == word.size());
    }

    int numMatchingSubseq(string s, vector<string>& words) {

        int ans = 0;

        for(string &word : words) {
            if(isSubsequence(s, word))
                ans++;
        }

        return ans;
    }
};