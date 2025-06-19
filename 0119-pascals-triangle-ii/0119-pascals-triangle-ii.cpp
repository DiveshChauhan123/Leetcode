class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>nums(34);
        nums[0]={1};
        nums[1]={1,1};
        for(int i=2;i<34;i++){
            vector<int>ans(i+1);
            ans[0]=1;
            ans[i]=1;
            for(int j=1;j<i;j++){
                ans[j]=nums[i-1][j]+nums[i-1][j-1];
            }
            nums[i]=ans;
        }
        return nums[rowIndex];
    }
};