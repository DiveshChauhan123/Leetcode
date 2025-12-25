class Solution {
public:
    bool isVowel(char c) {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }

    int countVowels(const string& w) {
        int cnt = 0;
        for (char c : w)
            if (isVowel(c)) cnt++;
        return cnt;
    }

    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> words;
        string w;

        while (ss >> w) words.push_back(w);

        if (words.empty()) return s;

        int target = countVowels(words[0]);

        for (int i = 1; i < words.size(); i++) {
            if (countVowels(words[i]) == target) {
                reverse(words[i].begin(), words[i].end());
            }
        }

        string res;
        for (int i = 0; i < words.size(); i++) {
            if (i) res += " ";
            res += words[i];
        }

        return res;
    }
};
