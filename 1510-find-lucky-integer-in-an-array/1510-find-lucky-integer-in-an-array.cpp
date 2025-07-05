class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        int result=-1;
        for(auto i:arr){
            if(mp[i]==i){
                result=max(result,mp[i]);
            }
        }
        return result;
    }
};