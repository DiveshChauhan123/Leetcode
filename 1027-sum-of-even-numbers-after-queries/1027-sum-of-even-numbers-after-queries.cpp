class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int odd=0;
        int even=0;
        for(auto &i :nums){
            if(i%2==0)even+=i;
            else{
                odd+=i;
            }
        }
        vector<int>result;
        for(int i=0;i<queries.size();i++){
            int x=queries[i][0];
            int y=queries[i][1];
            int z=nums[y]+x;
            if((nums[y]+x)%2==0){
                if(nums[y]%2==0){
                    even-=nums[y];
                    even+=z;
                    nums[y]=z;
                }
                else{
                    odd-=nums[y];
                    even+=z;
                    nums[y]=z;
                }
                result.push_back(even);
            }
            else{
                if(nums[y]%2==0){
                    even-=nums[y];
                    odd+=z;
                    nums[y]=z;
                }
                else{
                    odd-=nums[y];
                    odd+=z;
                    nums[y]=z;
                }
                result.push_back(even);
            }
        }
        return result;
    }
};