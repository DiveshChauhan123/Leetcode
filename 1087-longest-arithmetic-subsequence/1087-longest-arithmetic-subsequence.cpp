class Solution {
public:
int t[1001][1003];
    int longestArithSeqLength(vector<int>& nums) {
        int result=0;
        int n=nums.size();
        memset(t,-1,sizeof(t));
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff=nums[i]-nums[j]+501;
                t[i][diff]=t[j][diff]>0?t[j][diff]+1:2;
                result=max(result,t[i][diff]);
            }
        }
        return result;
    }
};