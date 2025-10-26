class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto [k,f]:mp){
            pq.push({f,k});
        }
        string p;
        while(!pq.empty() ){
            auto i=pq.top();
            pq.pop();
            for(int j=0;j<i.first;j++){
                p+=i.second;
            }
        }
        return p;
    }
};