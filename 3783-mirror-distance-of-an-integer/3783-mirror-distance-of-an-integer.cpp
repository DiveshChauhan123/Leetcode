class Solution {
public:
    int mirrorDistance(int n) {
        int reverse=0;
        int x=n;
        while(n>0){
            int rem=n%10;
            n/=10;
            reverse=reverse*10+rem;
        }
        return abs(x-reverse);
    }
};