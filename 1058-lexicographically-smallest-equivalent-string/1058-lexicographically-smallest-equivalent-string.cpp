class Solution {
public:
char dfs(unordered_map<char,list<char>>&mp,char src,vector<int>&visited){
    visited[src-'a']=1;
    char ch=src;
    for(auto neigh:mp[src]){
        if(visited[neigh-'a']==0){
            
            ch=min(ch,dfs(mp,neigh,visited));
        }
    }
    return ch;
}
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char,list<char>>mp;
        for(int i=0;i<s1.size();i++){
            mp[s1[i]].push_back(s2[i]);
            mp[s2[i]].push_back(s1[i]);
        }
        string s;
        for(int i=0;i<baseStr.size();i++){
            vector<int>visited(26,0);
            char c=dfs(mp,baseStr[i],visited);
            s.push_back(c);
        }
        return s;
    }
};