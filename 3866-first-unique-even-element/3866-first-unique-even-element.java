class Solution {
    public int firstUniqueEven(int[] nums) {
        Map<Integer,Integer>mp=new HashMap<>();
        for(int num:nums){
            mp.put(num,mp.getOrDefault(num,0)+1);
        }
        for(int num:nums){
            if(num%2==0 && mp.get(num)==1)return num;
        }
        return -1;
    }
}