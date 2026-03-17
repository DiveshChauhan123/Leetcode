class Solution {
    public boolean check(int[] nums) {
        boolean a=false;
        for(int i=1;i<nums.length;i++){
            if(nums[i]>=nums[i-1])continue;
            else if(nums[0]>=nums[i] && !a && nums[0]>=nums[nums.length-1])a=true;
            else{
                return false;
            }
        }
        return true;
    }
}