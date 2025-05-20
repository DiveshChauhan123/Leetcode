class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<long long>ans(nums.size(),0);
        for(int i=0;i<queries.size();i++){
            int x=queries[i][0];
            int y=queries[i][1];
            ans[x]++;
            if(y+1<nums.size())ans[y+1]--;
        }
        for(int i=1;i<nums.size();i++){
            ans[i]+=ans[i-1];
        }
        for(int i=0;i<nums.size();i++){
            nums[i]-=min(1LL*nums[i],ans[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0)return false;
        }
        return true;
    }
};