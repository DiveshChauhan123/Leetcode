class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[0]=-1;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int x=sum%k;
            if(mp.find(x)!=mp.end()){
                if(i-mp[x]>=2)return true;
            }
            else{
                mp[x]=i;
            }
        }
        return false;
    }
};