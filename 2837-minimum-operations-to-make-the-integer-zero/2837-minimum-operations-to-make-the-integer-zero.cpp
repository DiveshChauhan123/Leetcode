class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        long long mindiff=LLONG_MAX;
        int index=0;
        for(int i = 1; i <= 60; i++){  
            long long val = 1LL * num1 - 1LL * i * num2;
            if(val < 0) continue; 

            int count = 0;
            long long temp = val;
            while(temp != 0){
                if(temp & 1) count++;
                temp >>= 1;   // ✅ fix applied
            }

            if(count <= i && i <= val) { 
                return i;
            }
        }
        return -1;
    }
};