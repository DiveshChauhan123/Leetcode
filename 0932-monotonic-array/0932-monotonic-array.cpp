class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc=true;
        bool dec=true;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<=nums[i+1])continue;
            else{
                inc=false;
                break;
            }
        }
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>=nums[i+1])continue;
            else{
                dec=false;
                break;
            }
        }
        if(inc || dec)return true;
        return false;
    }
};