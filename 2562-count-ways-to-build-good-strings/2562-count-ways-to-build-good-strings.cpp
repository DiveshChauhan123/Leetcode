class Solution {
public:
int z,o,l,h;
const int MOD=1e9+7;
int solve(int s,vector<int>&dp){
    if(s>h)return 0;
    if(dp[s]!=-1)return dp[s];

    bool ans=0;
    if(s>=l && s<=h)ans=1;
    int addz=solve(s+z,dp);
    int addo=solve(s+o,dp);
    return dp[s]=(ans+addo+addz)%MOD;
}
    int countGoodStrings(int low, int high, int zero, int one) {
        z=zero,o=one,l=low,h=high;
        vector<int>dp(high+1,-1);
        return solve(0,dp);
    }
};