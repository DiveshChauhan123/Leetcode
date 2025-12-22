class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        vector<string>words;
        string word;
        while(ss>>word){
            words.push_back(word);
        }
        if (pattern.size() != words.size())
            return false;
        unordered_map<char,string>mp;
        unordered_map<string,char>mp2;
        for(int i=0;i<pattern.size();i++){
            string p=words[i];
            char c=pattern[i];
            if(mp.count(c) && mp[c]!=p){
                return false;
            }
            if(mp2.count(p) && mp2[p]!=c){
                return false;
            }
            mp[c]=p;
            mp2[p]=c;
        }
        return true;
    }
};