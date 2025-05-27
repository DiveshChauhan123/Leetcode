class Solution {
public:
    int differenceOfSums(int n, int m) {
        int counta=0,countb=0;
        for(int i=1;i<=n;i++){
            if(i%m!=0)counta+=i;
            else{
                countb+=i;
            }
        }
        return counta-countb;
    }
};