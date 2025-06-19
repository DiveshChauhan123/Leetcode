class Solution {
public:
int n,m,k;
int t[101][101];
bool solve(string s1,string s2,string s3,int i,int j){
    if(i==n && j==m && i+j==k){
        return true;
    }
    if(i+j>=k)return false;
    if(t[i][j]!=-1)return t[i][j];
    bool result=false;
    if(s1[i]==s3[i+j]){
        result=solve(s1,s2,s3,i+1,j);
    }
    if(result){
        return t[i][j]=true;
    }
    if(s2[j]==s3[i+j]){
        result=solve(s1,s2,s3,i,j+1);
    }
    return t[i][j]=result;
}
    bool isInterleave(string s1, string s2, string s3) {
       n=s1.size(),m=s2.size(),k=s3.size();
       memset(t,-1,sizeof(t));
       return solve(s1,s2,s3,0,0); 
    }
};