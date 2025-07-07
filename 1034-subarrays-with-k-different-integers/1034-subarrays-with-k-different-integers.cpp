class Solution {
public:
int sliding_window(vector<int>&nums,int k){
    unordered_map<int,int>mp;
    int i=0;
    int j=0;
    int count=0;
    int unique=0;
    while(j<nums.size()){
        mp[nums[j]]++;
        if(mp[nums[j]]==1)unique++;
        while(unique>k){
            mp[nums[i]]--;
            if(mp[nums[i]]==0)unique--;
            i++;
        }
        count+=(j-i+1);
        j++;
    }
    return count;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return sliding_window(nums,k)-sliding_window(nums,k-1);
    }
};