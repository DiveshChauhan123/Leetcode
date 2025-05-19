class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,1e7));
        for(int i=0;i<n;i++){
            dp[n-1][i]=matrix[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int x=INT_MAX;
                int y=INT_MAX;
                int z=dp[i+1][j];
                if(j-1>=0)x=dp[i+1][j-1];
                if(j+1<n)y=dp[i+1][j+1];
                dp[i][j]=min(x,min(y,z))+matrix[i][j];
            }
        }
        int result=INT_MAX;
        for(int i=0;i<n;i++){
            result=min(result,dp[0][i]);
        }
        return result;
    }
};