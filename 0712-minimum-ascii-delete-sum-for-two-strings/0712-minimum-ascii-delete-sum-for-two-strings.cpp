class Solution {
public:
int dp[1001][1001];
int solve(string &s1,string &s2,int i,int j){
    if (i == s1.size() && j == s2.size()) return 0;
    if (dp[i][j] != -1) return dp[i][j];

        // End of s1
        if (i == s1.size()) {
            int sum = 0;
            for (int k = j; k < s2.size(); ++k) sum += s2[k];
            return dp[i][j] = sum;
        }

        // End of s2
        if (j == s2.size()) {
            int sum = 0;
            for (int k = i; k < s1.size(); ++k) sum += s1[k];
            return dp[i][j] = sum;
        }
    if(s1[i]==s2[j]){
        return dp[i][j]=solve(s1,s2,i+1,j+1);
    }
    int x=int(s1[i])+solve(s1,s2,i+1,j);
    int y=int(s2[j])+solve(s1,s2,i,j+1);
    return dp[i][j]=min(x,y);
}
    int minimumDeleteSum(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        return solve(s1,s2,0,0);
    }
};