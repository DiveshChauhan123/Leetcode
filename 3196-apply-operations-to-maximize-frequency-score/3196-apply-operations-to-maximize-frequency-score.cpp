class Solution {
public:
typedef long long int ll;
bool possible(vector<int>&nums,int len,long long k,int n,vector<long long>&prefix){
    if(len==0)return false;
    int i=0;
    int j=len-1;
    while(j < n) {
            ll target_idx = (i+j) / 2;
            ll target     = nums[target_idx];
            
            
            ll operations_left  = 0;
            ll operations_right = 0;
            
            if(target_idx == 0) {
                operations_left = 0;
            } else {
                operations_left = abs(((target_idx - i) * target) - (prefix[target_idx-1] - (i > 0 ? prefix[i-1] : 0)));
            }
            
            operations_right    = abs(((j - target_idx) * target) - (prefix[j] - prefix[target_idx]));
          
            if(operations_right + operations_left <= k) {
                return true;
            }
            
            i++;
            j++;
            
        }
    return false;    

}
    int maxFrequencyScore(vector<int>& nums, long long k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<long long>prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        int s=1;
        int e=n;
        int result=1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(possible(nums,mid,k,n,prefix)){
                result=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return result;
    }
};