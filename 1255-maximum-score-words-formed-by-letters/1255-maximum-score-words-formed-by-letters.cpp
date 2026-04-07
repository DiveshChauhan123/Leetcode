class Solution {
public:
int maxi;
void solve(int i,vector<string>&words,vector<int>&score,int curr,vector<int>&freq){
    maxi=max(maxi,curr);
    if(i>=words.size())return;
    int j=0;
    int sc=0;
    vector<int>temp=freq;
    while(j<words[i].size()){
        char c=words[i][j];
        temp[c-'a']--;

        if(temp[c-'a']<0)break;
        sc+=score[words[i][j]-'a'];
        j++;
    }
    if(j==words[i].size()){
        solve(i+1,words,score,curr+sc,temp);
    }
    solve(i+1,words,score,curr,freq);
}
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int>freq(26,0);
        for(char c:letters){
            freq[c-'a']++;
        }
        maxi=INT_MIN;
        solve(0,words,score,0,freq);
        return maxi;
    }
};