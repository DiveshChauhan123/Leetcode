class Solution {
public:
int n;
int t[1001][101][2];
int solve(vector<int>&prices,int i,int k,int to_do){
    if(i>=n)return 0;
    if(k==0)return 0;
    if(t[i][k][to_do]!=-1)return t[i][k][to_do];
    int skip=solve(prices,i+1,k,to_do);
    int take=0;
    if(to_do){
        take=solve(prices,i+1,k,0)-prices[i];
    }
    else{
        take=prices[i]+solve(prices,i+1,k-1,1);
    }
    return t[i][k][to_do]=max(skip,take);
}
    int maxProfit(int k, vector<int>& prices) {
        n=prices.size();
        memset(t,-1,sizeof(t));
        return solve(prices,0,k,1);
    }
};