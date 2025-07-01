class Solution {
public:
    int possibleStringCount(string word) {
        int result=1;
        char prev=word[0];
        int count=1;
        for(int i=1;i<word.size();i++){
            if(word[i]==prev){
                count++;
            }
            else{
                prev=word[i];
                result+=count-1;
                count=1;
            }
        }
        result+=count-1;
        return result;
    }
};