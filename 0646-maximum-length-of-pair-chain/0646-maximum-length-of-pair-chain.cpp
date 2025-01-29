class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<int>dp(pairs.size(),1);
        for(int i=0;i<pairs.size();i++){
            for(int j=0;j<i;j++){
                int skip=dp[i];
                int take=0;
                if(pairs[i][0]>pairs[j][1]){
                    take=dp[j]+1;
                }
                dp[i]=max(skip,take);
            }
        }
        return dp[n-1];
    }
};