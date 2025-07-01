class Solution {
public:
int n,m;
int dp[1001][1001];
int solve(string s,string t,int i,int j){
    if(j==m)return 1;
    if(i==n)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j]){
        return dp[i][j]=solve(s,t,i+1,j+1)+solve(s,t,i+1,j);
    }
    return dp[i][j]=solve(s,t,i+1,j);
}
    int numDistinct(string s, string t) {
        n=s.size();
        m=t.size();
        memset(dp,-1,sizeof(dp));
        return solve(s,t,0,0);
    }
};