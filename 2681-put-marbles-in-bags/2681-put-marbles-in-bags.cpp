class Solution {
public:
    long long putMarbles(vector<int>& ans, int k) {
        int n=ans.size();
        int m=n-1;
        vector<int>pairsum(m,0);
        for(int i=0;i<m;i++){
            pairsum[i]=ans[i]+ans[i+1];
        }
        sort(pairsum.begin(),pairsum.end());
        long long mini=0;
        long long maxi=0;
        for(int i=0;i<k-1;i++){
            mini+=pairsum[i];
            maxi+=pairsum[m-i-1];
        }
        return maxi-mini;
    }
};