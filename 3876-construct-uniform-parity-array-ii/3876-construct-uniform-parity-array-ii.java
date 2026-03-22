class Solution {
    public boolean makeodd(int[] nums1){
        int odd=Integer.MAX_VALUE;
        for(int i=0;i<nums1.length;i++){
            if(nums1[i]%2==1)odd=Math.min(nums1[i],odd);
        }
        int even=Integer.MAX_VALUE;
        for(int i=0;i<nums1.length;i++){
            if(nums1[i]%2==0)even=Math.min(nums1[i],even);
        }
        if(odd==Integer.MAX_VALUE)return true;
        if(even==Integer.MAX_VALUE)return true;
        for(int i=0;i<nums1.length;i++){
            if(nums1[i]%2==0){
                if(nums1[i]<odd)return false;
            }
        }
        return true;
    }
    public boolean makeeven(int [] nums1){
        int odd=Integer.MAX_VALUE;
        for(int i=0;i<nums1.length;i++){
            if(nums1[i]%2==1)odd=Math.min(nums1[i],odd);
        }
        int even=Integer.MAX_VALUE;
        if(odd==Integer.MAX_VALUE)return true;
        for(int i=0;i<nums1.length;i++){
            if(nums1[i]%2==0)even=Math.min(nums1[i],even);
        }
        if(even==Integer.MAX_VALUE)return true;
        for(int i=0;i<nums1.length;i++){
            if(nums1[i]%2==1){
                if(nums1[i]==odd)return false;
            }
        }
        return true;
    }
    public boolean uniformArray(int[] nums1) {
        return (makeodd(nums1) || makeeven(nums1));
    }
}