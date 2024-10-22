class Solution {
public:
void dfs(vector<vector<int>>graph,int src,int target,vector<vector<int>>&result,vector<int>&temp){
    temp.push_back(src);
    if(src==target){
        result.push_back(temp);
    }
    else{
        for(int &v: graph[src]){
            dfs(graph,v,target,result,temp);
        }
    }
    temp.pop_back();
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>result;
        vector<int>temp;
        dfs(graph,0,graph.size()-1,result,temp);
        return result;
    }
};