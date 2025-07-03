class Solution {
public:
    char kthCharacter(int k) {
        string word="a";
        while(word.size()<k){
            string add="";
            for(int i=0;i<word.size();i++){
                int x=word[i];
                if(x=='z')add+='a';
                else{
                    add+=(x+1);
                }
            }
            word+=add;
        }
        return word[k-1];
    }
};