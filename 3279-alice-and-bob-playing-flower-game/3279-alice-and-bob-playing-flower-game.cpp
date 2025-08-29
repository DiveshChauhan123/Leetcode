class Solution {
public:
    long long flowerGame(int n, int m) {
        long long evenno1=0;
        long long evenno2=0;
        long long oddno1=0;
        long long oddno2=0;
        if(n%2==0){
            evenno1=n/2;
            oddno1=n/2;
        }
        else{
            evenno1=n/2;
            oddno1=n/2+1;
        }
        if(m%2==0){
            evenno2=m/2;
            oddno2=m/2;
        }
        else{
            evenno2=m/2;
            oddno2=m/2+1;
        }
        return evenno1*oddno2+evenno2*oddno1;
    }
};