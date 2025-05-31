class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int x=0,y=0;
        for(int i=1;i<=n;i++){
            if(mp[i]==0)x=i;
            else if(mp[i]==2)y=i;
        }
        return {y,x};
    }
};