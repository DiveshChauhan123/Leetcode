class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        for(auto [k,f]:freq){
            mp[f].push_back(k);
        }
        for(int i=0;i<nums.size();i++){
            if(mp[freq[nums[i]]].size()==1)return nums[i];
        }
        return -1;
    }
};