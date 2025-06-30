class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int size=0;
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
        }
        for (auto& [num, freq] : mp) {
            if (mp.count(num + 1)) {
                size = max(size, freq + mp[num + 1]);
            }
        }
        return size==1?0:size;
    }
};