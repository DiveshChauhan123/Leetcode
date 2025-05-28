class Solution {
public:

int solve(string &s ,string &r,int n,int m,vector<vector<int>>&dp){
    if(n==0 || m==0)return 0;
    if(dp[n][m]!=-1)return dp[n][m];
    if(s[n-1]==r[m-1]){
        return dp[n][m]=1+solve(s,r,n-1,m-1,dp);
    }
    return dp[n][m]=max(solve(s,r,n-1,m,dp),solve(s,r,n,m-1,dp));
}
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        string r=s;
        reverse(r.begin(),r.end());
        return n-solve(s,r,n,n,dp);
    }
};