class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int>mp;
        for(auto num:nums){
            int x=((num%value)+value)%value;
            mp[x]++;
        }
        int MEX=0;
        while(mp[MEX%value]>0){
            mp[MEX%value]--;
            MEX++;
        }
        return MEX;
    }
};