class Solution {
public:
bool solve(string s,string t,int i,int j){
    if(i==s.size())return true;
    if(j==t.size())return false;

    if(s[i]!=t[j]){
        return solve(s,t,i,j+1);
    }
    return solve(s,t,i+1,j+1);
}
    bool isSubsequence(string s, string t) {
        if(s.empty())return true;
        return solve(s,t,0,0);
    }
};