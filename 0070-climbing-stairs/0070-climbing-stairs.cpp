class Solution {
// int t[46];
// int solve(int n){
//     if(n<0)return 0;
//     if(n==0)return 1;
//     if(t[n]!=-1)return t[n];
//     int take=solve(n-1);
//     int nottake=solve(n-2);
//     return t[n]=nottake+take;
// }
//     int climbStairs(int n) {
//         memset(t,-1,sizeof(t));
//         return solve(n);
//     }
// };
public:
int t[46];
    int climbStairs(int n) {
        int prev2=1;
        int prev1=0;
        for(int i=1;i<=n;i++){
            t[i]=prev1+prev2;
            prev1=prev2;
            prev2=t[i];
        }
        return t[n];
    }
};