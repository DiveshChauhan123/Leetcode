class Solution {
public:
    int reverseBits(int n) {
        vector<int>ans(32,0);
        int x=31;
        while(n>0){
            if(n%2){
                ans[x--]=1;
            }
            else{
                ans[x--]=0;
            }
            n=n/2;
        }
        reverse(ans.begin(),ans.end());
        int result=0;
        int y=0;
        for(int i=31;i>=0;i--){
            result|=(ans[i]<<y);
            y++;
        }
        return result;
    }
};