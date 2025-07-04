class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i=0,j=0;
        int counta=0,countb=0;
        int result=0;
        while(j<answerKey.size()){
            if(answerKey[j]=='T')counta++;
            else{
                countb++;
            }
            if(counta<=k || countb<=k){
                result=j-i+1;
            }
            else{
                if(answerKey[i]=='T')counta--;
                else{
                    countb--;
                }
                i++;
            }
            j++;
        }
        return result;
    }
};