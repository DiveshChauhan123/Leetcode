class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int op=0;
        while(startValue<target){
            if(startValue==target){
                return op;
            }
            if(target%2==0){
                target/=2;
                op++;
            }
            else{
                target++;
                op++;
            }
        }
        if(startValue!=target){
            op+=abs(startValue-target);
        }
        return op;
    }
};