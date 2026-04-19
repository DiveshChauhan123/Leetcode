class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>maxi(nums.size(),0);
        vector<int>mini(nums.size(),0);

        maxi[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            maxi[i]=max(maxi[i-1],nums[i]);
        }
        mini[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            mini[i]=min(mini[i+1],nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            int x=maxi[i];
            int y=mini[i];
            if(x-y<=k)return i;
        }
        return -1;
    }
};