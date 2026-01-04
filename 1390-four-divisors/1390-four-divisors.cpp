class Solution {
public:

    int sumFourDivisors(vector<int>& nums) {
        int sum=0;
        for(int x:nums){
            int cnt=0;
            int s=0;
            for(int j=1;j*j<=x;j++){
                if(x%j==0){
                    int t=x/j;
                cnt++;
                s+=j;
                if(t!=j){
                    cnt++;
                    s+=t;
                }
                if(cnt>4)break;
                }
            }
            if(cnt==4)sum+=s;
        }
        return sum;
    }
};