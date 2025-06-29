class Solution {
public:
long long check(vector<int>&nums,vector<int>&cost,int mid){
    long long value=0;
    for(int i=0;i<nums.size();i++){
        value+=1LL*abs(nums[i]-mid)*cost[i];
    }
    return value;
}
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long s=*min_element(nums.begin(),nums.end());
        long long result=LLONG_MAX;
        long long e=*max_element(nums.begin(),nums.end());
        while(s<=e){
            long long mid=s+(e-s)/2;
            long long cost1=check(nums,cost,mid);
            long long cost2=check(nums,cost,mid+1);
            result=min(cost1,cost2);
            if(cost1>cost2){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            
        }
        return result==LLONG_MAX?0:result;
    }
};