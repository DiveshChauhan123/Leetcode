class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string p;
        for(int i=0;i<words.size();i++){
            string word=words[i];
            int sum=0;
            for(char c:word){
                sum+=(weights[int(c)-97]);
            }
            sum=sum%26;
            p+=(char(25-sum+97));
        }
        return p;
    }
};