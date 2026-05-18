class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        for(int i=1;i<s.size();i++){
            char prev=s[i-1];
            char curr=s[i];
            if(abs((prev-'0')-(curr-'0'))>2){
                return false;
            }
        }
        return true;
    }
};