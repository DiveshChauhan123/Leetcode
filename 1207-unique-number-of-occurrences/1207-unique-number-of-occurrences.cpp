class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto i:arr)mp[i]++;
        unordered_set<int>seen;
        for(auto i:mp){
            if(!seen.insert(i.second).second)return false;
        }
        return  true;
    }
};