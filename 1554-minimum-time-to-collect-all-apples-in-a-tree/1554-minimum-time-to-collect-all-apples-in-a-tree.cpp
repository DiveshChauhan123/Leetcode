class Solution {
public:
int dfs(unordered_map<int,list<int>>&mp,int src,int parent, vector<bool>& hasApple){
    int time=0;
    for(int child:mp[src]){
        if(child==parent)continue;
        int time_child=dfs(mp,child,src,hasApple);
        if(time_child>0 || hasApple[child]){
            time+=time_child+2;
        }
    }
    return time;
}
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int,list<int>>mp;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        return dfs(mp,0,-1,hasApple);
        
    }
};