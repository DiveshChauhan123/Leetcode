class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
       vector<long long>result(nums.size());
       unordered_map<int,vector<long long>>mp;
       for(int i=0;i<nums.size();i++){
        mp[nums[i]].push_back(i);
       }
       for(auto [val,arr]:mp){
        int m=arr.size();
        vector<long long>pref(m);
        pref[0]=arr[0];
        for(int i=1;i<m;i++){
            pref[i]=pref[i-1]+arr[i];
        }
        for(int i=0;i<m;i++){
            long long left=i*arr[i]-(i>0?pref[i-1]:0);
            long long right=pref[m-1]-pref[i]-(long long)(m-i-1)*arr[i];
            result[arr[i]]=left+right;
        }
       }
       return result;
    }
};