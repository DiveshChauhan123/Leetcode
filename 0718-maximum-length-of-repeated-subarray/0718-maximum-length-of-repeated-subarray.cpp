class Solution {
public:
int t[1001][1001];
int solve(vector<int>&nums1,vector<int>&nums2,int i,int j){
    if(i>=nums1.size() || j>=nums2.size())return 0;
    if(t[i][j]!=-1)return t[i][j];
    if(nums1[i]==nums2[j]){
        return t[i][j]=1+solve(nums1,nums2,i+1,j+1);
    }
    return t[i][j]=0;
}
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        memset(t,-1,sizeof(t));
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                ans = max(ans, solve(nums1, nums2, i, j));
            }
        }

        return ans;
    }
};