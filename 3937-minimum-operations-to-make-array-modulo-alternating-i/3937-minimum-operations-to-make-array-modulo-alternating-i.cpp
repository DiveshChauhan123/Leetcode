class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans=INT_MAX;
        for(int x=0;x<k;x++){
            for(int y=0;y<k;y++){
                if(x==y)continue;
                int cost=0;
                for(int i=0;i<nums.size();i++){
                    int r = nums[i] % k;
                    int target = (i % 2 == 0 ? x : y);

                    int inc = (target - r + k) % k;
                    int dec = (r - target + k) % k;

                    cost += min(inc, dec);
                }
                ans=min(ans,cost);
            }
        }
        return ans;
    }
};