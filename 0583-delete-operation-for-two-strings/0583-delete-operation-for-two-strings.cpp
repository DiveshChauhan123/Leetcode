class Solution {
public:
int t[501][501];
int solve(string word1,string word2,int i,int j){
    if(word1.size()<=i || word2.size()<=j)return max(word1.size()-i,word2.size()-j);
    if(t[i][j]!=-1)return t[i][j];
    if(word1[i]==word2[j]){
        return t[i][j]=solve(word1,word2,i+1,j+1);
    }
    return t[i][j]=1+min(solve(word1,word2,i+1,j),solve(word1,word2,i,j+1));
}
    int minDistance(string word1, string word2) {
        memset(t,-1,sizeof(t));
        return solve(word1,word2,0,0);
    }
};