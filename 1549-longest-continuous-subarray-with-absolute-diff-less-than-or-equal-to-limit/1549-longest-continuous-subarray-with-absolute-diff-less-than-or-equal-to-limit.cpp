class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int i=0,j=0;
        multiset<int>s;
        int result=0;
        while(j<nums.size()){
            s.insert(nums[j]);
            while(*s.rbegin()-*s.begin()>limit){
                s.erase(s.find(nums[i]));
                i++;
            }
            result=max(j-i+1,result);
            j++;
        }
        return result;
    }
};