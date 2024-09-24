class Solution {
public:
void bfs(int i,vector<int>&visited,unordered_map<int,list<int>>&mp){
    visited[i]=1;
    queue<int>q;
    q.push(i);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:mp[u]){
            if(visited[v]==0){
                q.push(v);
                visited[v]=1;
            }
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        unordered_map<int,list<int>>mp;
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1){
                    mp[i].push_back(j);
                }
            }
        }
        int count=0;
        vector<int>visited(n,0);
        for(int i=0;i<isConnected.size();i++){
            if(visited[i]==0){
                bfs(i,visited,mp);
                count++;
            }
        }return count;
    }
};