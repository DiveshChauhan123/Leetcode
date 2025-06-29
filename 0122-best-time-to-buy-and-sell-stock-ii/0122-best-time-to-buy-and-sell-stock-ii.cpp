class Solution {
public:
int n;
vector<vector<int>>t;
//do means wheather to buy or sell the stock
int solve(vector<int>&prices,int index,int d){
    if(index>=n)return 0;
    if(t[index][d]!=-1)return t[index][d];
    int do_nothing=0;
    int do_something=0;
    if(d){
        do_something=solve(prices,index+1,false)-prices[index];
        do_nothing=solve(prices,index+1,d);
    }
    else{
        do_something=prices[index]+solve(prices,index+1,true);
        do_nothing=solve(prices,index+1,d);
    }
    return t[index][d]=max(do_nothing,do_something);
}
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        t.assign(n,vector<int>(2,-1));
        return solve(prices,0,1);
    }
};