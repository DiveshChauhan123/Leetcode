class Solution {
public:
    int smallestNumber(int n) {
        int x=1;
        int a=2;
        while(x<n){
            a*=2;
            x=a-1;
        }
        return x;
    }
};