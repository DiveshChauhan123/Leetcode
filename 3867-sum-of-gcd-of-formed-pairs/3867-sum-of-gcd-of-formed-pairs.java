class Solution {
    public int gcd(int a,int b){
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    public long gcdSum(int[] nums) {
        ArrayList<Integer>arr=new ArrayList<>();
        arr.add(nums[0]);
        for(int i=1;i<nums.length;i++){
            arr.add(Math.max(nums[i],arr.get(arr.size()-1)));
        }
        for(int i=0;i<nums.length;i++){
            nums[i]=gcd(arr.get(i),nums[i]);
        }
        Arrays.sort(nums);
        long sum=0;
        int start=0;
        int end=nums.length-1;
        while(start<end){
            sum+=gcd(nums[start],nums[end]);
            start++;
            end--;
        }
        return sum;
    }
}