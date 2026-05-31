class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int,int>mp;
        string s=to_string(n);
        for(int i=0;i<s.size();i++){
            int num=s[i]-'0';
            mp[num]++;
        }
        int count=0;
        for(auto [k,f]:mp){
            count+=(k*f);
        }
        return count;
    }
};