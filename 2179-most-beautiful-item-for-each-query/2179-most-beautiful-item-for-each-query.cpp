class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        vector<int>ans(items.size()),result,nums;
        ans[0]=items[0][1];
        for(int i=0;i<items.size();i++){
            if(i>0){
                ans[i]=max(items[i][1],ans[i-1]);
            }
            nums.push_back(items[i][0]);
        }
        for(int i=0;i<queries.size();i++){
            int index=upper_bound(nums.begin(),nums.end(),queries[i])-nums.begin()-1;
            if(index<0)result.push_back(0);
            else{
                result.push_back(ans[index]);
            }
        }
        return result;
    }
};