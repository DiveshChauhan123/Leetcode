class Solution {
public:
bool check(vector<int>&nums,int p,int mid){
    int size=1;
    int pair=0;
    for(int i=0;i<nums.size()-1;i=i+size){
        if(nums[i+1]-nums[i]<=mid){
            pair++;
            size=2;
        }
        else{
            size=1;
        }
    }
    return p<=pair?true:false;
}
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int s=0;
        int result=0;
        int e=nums[nums.size()-1]-nums[0];
        while(s<=e){
            int mid=s+(e-s)/2;
            if(check(nums,p,mid)){
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