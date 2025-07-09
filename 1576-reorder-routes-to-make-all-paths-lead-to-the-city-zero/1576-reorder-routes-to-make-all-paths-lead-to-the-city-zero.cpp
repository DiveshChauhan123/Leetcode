class Solution {
public:
int count=0;
void dfs(int n,int node,int parent,unordered_map<int,vector<pair<int,int>>>&mp){
    for(auto k:mp[node]){
        int neigh=k.first;
        int cost=k.second;
        if(neigh!=parent ){
            if(cost==1)count++;
            dfs(n,neigh,node,mp);
        }
    }
}
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<pair<int,int>>>mp;
        for(int i=0;i<connections.size();i++){
            mp[connections[i][0]].push_back({connections[i][1],1});
            mp[connections[i][1]].push_back({connections[i][0],0});
        }
        dfs(n,0,-1,mp);
        return count;
    }
};