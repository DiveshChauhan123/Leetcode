class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sum=nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int a=nums[i]+nums[j]+nums[k];
                if(abs(sum-target)>abs(a-target)){
                    sum=a;
                }
                else if(a>target){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return sum;
    }
};