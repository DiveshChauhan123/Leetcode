class Solution {
public:
int t[601][101][101];
int solve(vector<string>& strs, int m, int n,int index){
    if(index>=strs.size())return 0;
    if(t[index][m][n]!=-1)return t[index][m][n];
    int one=0;
    int zero=0;
    for(int i=0;i<strs[index].size();i++){
        if(strs[index][i]=='0')zero++;
        else{
            one++;
        }
    }
    int nottake=0;
    int take=0;
    if(zero>m || one>n){
        return t[index][m][n]=solve(strs,m,n,index+1);
    }
    nottake=solve(strs,m,n,index+1);
    take=1+solve(strs,m-zero,n-one,index+1);
    return t[index][m][n]=max(take,nottake);
}
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(t,-1,sizeof(t));
        return solve(strs,m,n,0);
    }
};