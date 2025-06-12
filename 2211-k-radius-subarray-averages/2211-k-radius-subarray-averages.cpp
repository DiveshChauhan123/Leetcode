class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>prefix(n,0);
        vector<int>result(n,-1);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        int x=2*k+1;
        for(int i=k;i<n-k;i++){
            result[i]=int((prefix[i+k]-prefix[i-k]+nums[i-k])/x);
        }
        return result;
    }
};