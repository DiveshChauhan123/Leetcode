class Solution {
    public void rotate(int[] nums, int k) {
        int [] arr=nums.clone();
        for(int i=0;i<nums.length;i++){
            nums[(i+k)%nums.length]=arr[i];
        }
    }
}