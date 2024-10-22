class Solution {
public:
void dfs(unordered_map<int,list<int>>&mp,string &labels,vector<int>&ans,vector<int>&count,int src,int parent){
    char label=labels[src];
    int count_before=count[label-'a'];
    count[label-'a']++;
    for(auto child:mp[src]){
        if(child==parent)continue;
        dfs(mp,labels,ans,count,child,src);
    }
    int count_after=count[label-'a'];
    ans[src]=count_after-count_before;
}
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int,list<int>>mp;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<int>ans(n,0);
        vector<int>count(26,0);
        dfs(mp,labels,ans,count,0,-1);
        return ans;
    }
};