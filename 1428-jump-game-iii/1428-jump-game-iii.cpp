class Solution {
public:
bool dfs(int start,vector<int>&visited,vector<int>&arr){
    visited[start]=1;
    if(arr[start]==0){
        return true;
    }
    bool a=false;
    bool b=false;
    if(start+arr[start]>=0 && start+arr[start]<arr.size() && visited[start+arr[start]]==0){
        a=dfs(start+arr[start],visited,arr);
    }
    if(start-arr[start]>=0 && start-arr[start]<arr.size() && visited[start-arr[start]]==0){
        b=dfs(start-arr[start],visited,arr);
    }
    return a||b;
}
    bool canReach(vector<int>& arr, int start) {
        vector<int>visited(arr.size(),0);
        return dfs(start,visited,arr);
    }
};