class Solution {
public:
int m=1e9+7;
int t[5001][12];
string color[12]={"RYR","YRY","RYG","YRG","GRG","RGR","YGR","GYR","RGY","YGY","GYG","GRY"};
int solve(int n,int prev){
    //base case
    if(n==0)return 1;
    if(t[n][prev]!=-1)return t[n][prev];
    int sum=0;
    string p=color[prev];
    for(int i=0;i<12;i++){
        if(i==prev)continue;
        bool conflict=false;
        string s=color[i];
        for(int j=0;j<=2;j++){
            if(p[j]==s[j]){
                conflict=true;
                break;
            }
        }
        if(!conflict){
            sum=(sum+solve(n-1,i))%m;
        }

    }
    return t[n][prev]=sum%m;
}
    int numOfWays(int n) {
        int result=0;
        memset(t,-1,sizeof(t));
        for(int i=0;i<12;i++){
            result=(result+solve(n-1,i))%m;
        }
        return result%m;
    }
};