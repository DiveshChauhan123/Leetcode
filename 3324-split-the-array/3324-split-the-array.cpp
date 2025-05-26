class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto & i:nums){
            mp[i]++;
            if(mp[i]>2)return false;
        }
        int counta=0,countb=0;
        bool a=true;
        for(auto [k,f]:mp){
            if(f%2==0){
                counta+=f/2;
                countb+=f/2;
            }
            else{
                if(a){
                    counta+=f;
                    a=false;
                }
                else{
                    countb+=f;
                    a=true;
                }
            }
        }
        return counta==countb;
    }
};