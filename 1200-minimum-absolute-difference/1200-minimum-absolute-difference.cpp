class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int mini=INT_MAX;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        vector<vector<int>>nums;
        for(int i=1;i<n;i++){
            mini=min(abs(arr[i]-arr[i-1]),mini);
        }
        for(int i=1;i<n;i++){
            if(mini==abs(arr[i]-arr[i-1])){
                nums.push_back({arr[i-1],arr[i]});
            }
        }
        return nums;
    }
};