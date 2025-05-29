class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>result;
        for(int i=0;i<strs.size();i++){
            string p=strs[i];
            sort(p.begin(),p.end());
            mp[p].push_back(strs[i]);
        }
        for(auto &i:mp){
            result.push_back(i.second);
        }
        return result;
    }
};