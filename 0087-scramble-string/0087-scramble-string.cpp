class Solution {
public:
bool solve(string s1,string s2,unordered_map<string,bool>&mp){
    if(s1==s2)return true;
    if(s1.length()!=s2.length())return false;
    int n=s1.size();
    string key=s1+"_"+s2;
    if(mp.find(key)!=mp.end())return mp[key];
    bool result=false;
    for(int i=1;i<s1.size();i++){
        bool swapped=solve(s1.substr(0,i),s2.substr(n-i,i),mp) && solve(s1.substr(i,n-i),s2.substr(0,n-i),mp);
        if(swapped){
            result=true;
            break;
        }
        bool notswapped=solve(s1.substr(0,i),s2.substr(0,i),mp) && solve(s1.substr(i,n-i),s2.substr(i,n-i),mp);
        if(notswapped){
            result=true;
            break;
        }
    }
    return mp[key]=result;
}
    bool isScramble(string s1, string s2) {
        unordered_map<string,bool>mp;
        return solve(s1,s2,mp);
    }
};