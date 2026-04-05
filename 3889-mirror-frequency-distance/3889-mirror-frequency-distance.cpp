class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<int,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]-'0']++;
        }
        int count=0;
        for(char c:s){
            int x=c-'0';
            if(x<=9 && mp[x]!=-1){
                count+=abs(mp[x]-mp[9-x]);
                mp[x]=-1;
                mp[9-x]=-1;
            }
            else if(mp[x]!=-1){
                count+=abs(mp[x]-mp[74-x+49]);
                mp[x]=-1;
                mp[74-x+49]=-1;
            }
        }
        return count;
    }
};