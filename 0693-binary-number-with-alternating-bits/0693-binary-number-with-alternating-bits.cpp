class Solution {
public:
    bool hasAlternatingBits(int n) {
        int rem=n%2;
        n/=2;
        while(n>0){
            if(n%2==rem)return false;
            rem=n%2;
            n/=2;
        }
        return true;
    }
};