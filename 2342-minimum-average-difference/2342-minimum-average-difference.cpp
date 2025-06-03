class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        long long start=0;
        int mini=INT_MAX;
        int index=0;
        long long end=accumulate(nums.begin(),nums.end(),1LL*0);
        long long y=end;
        for(int i=0;i<nums.size();i++){
            start+=nums[i];
            end-=nums[i];
            if(i==n-1){
                if(mini>y/n){
                    mini=y/n;
                    index=n-1;
                }
            }
            else if(mini>abs(start/(i+1)-end/(n-i-1))){
                index=i;
                mini=abs(start/(i+1)-end/(n-i-1));
            }
        }
        return index;
    }
};