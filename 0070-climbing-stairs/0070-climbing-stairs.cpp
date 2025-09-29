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
        t[0]=1;
        for(int i=1;i<=n;i++){
            t[i]+=t[i-1];
            if(i-2>=0){
                t[i]+=t[i-2];
            }
        }
        return t[n];
    }
};