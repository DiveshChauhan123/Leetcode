class Solution {
public:
int N;
int t[101][101][101];
const int MOD=1e9+7;
int solve(int i,int p,int people,int &minprofit,vector<int>& group, vector<int>& profit){
    if(people>N)return 0;
    if(i>=group.size()){
        if(p>=minprofit){
            return t[i][p][people]=1;
        };
        return 0;
    }
    if(t[i][p][people]!=-1)return t[i][p][people];
    int nottaken=solve(i+1,p,people,minprofit,group,profit);
    int taken=solve(i+1,min(p+profit[i],minprofit),people+group[i],minprofit,group,profit);
    return t[i][p][people]=(taken%MOD+nottaken%MOD)%MOD; 

}
    int profitableSchemes(int n, int minprofit, vector<int>& group, vector<int>& profit) {
        N=n;
        memset(t,-1,sizeof(t));
        return solve(0,0,0,minprofit,group,profit);
    }
};