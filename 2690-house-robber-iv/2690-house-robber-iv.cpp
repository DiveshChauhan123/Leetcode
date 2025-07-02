class Solution {
public:
bool possible(vector<int>&nums,int k ,int mid){
    int count=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]<=mid){
            count++;
            i++;
        }
    }
    return count>=k;
}
    int minCapability(vector<int>& nums, int k) {
        int n=nums.size();
        int result=0;
        int s=*min_element(nums.begin(),nums.end());
        int e=*max_element(nums.begin(),nums.end());
        while(s<=e){
            int mid=s+(e-s)/2;
            if(possible(nums,k,mid)){
                result=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return result;
    }
};