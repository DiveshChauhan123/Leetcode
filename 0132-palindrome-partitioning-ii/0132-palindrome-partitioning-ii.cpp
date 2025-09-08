class Solution {
public:
int t[2001];
vector<vector<bool>> precompute(string &s) {
        int n = s.size();
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        
        for (int i = 0; i < n; i++) pal[i][i] = true; // single chars
        for (int i = 0; i+1 < n; i++) 
            if (s[i] == s[i+1]) pal[i][i+1] = true;
        
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i+len-1 < n; i++) {
                int j = i+len-1;
                if (s[i] == s[j] && pal[i+1][j-1]) 
                    pal[i][j] = true;
            }
        }
        return pal;
    }
    int solve(int i, string &s, vector<vector<bool>> &pal){
        if(i>=s.size())return 0;
        int ans=INT_MAX;
        if(t[i]!=-1)return t[i];
        for(int j=i;j<s.size();j++){
            if(pal[i][j]){
                if(j==s.size()-1) ans=0;
                else{
                ans=min(ans,1+solve(j+1,s,pal));
            }
            }
        }
        return t[i]=ans;
    }
    int minCut(string s) {
        memset(t,-1,sizeof(t));
        auto pal = precompute(s);
        return solve(0, s, pal);
    }
};