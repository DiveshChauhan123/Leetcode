class Solution {
public:
int result=-1;
void dfs(int u,vector<int>&edges,vector<bool>&visited,vector<bool>&inrecursion,vector<int>&dist){
    if(u!=-1){
        visited[u]=true;
        inrecursion[u]=true;
        int v=edges[u];
        if(v!=-1 && !visited[v]){
            visited[v]=true;
            inrecursion[v]=true;
            dist[v]=dist[u]+1;
            dfs(v,edges,visited,inrecursion,dist);
        }
        else if(v!=-1 && inrecursion[v]==true){
            result=max(result,abs(dist[v]-dist[u])+1);
        }
        inrecursion[u]=false;
    }
    
}
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<bool>visited(n,false);
        vector<bool>inrecursion(n,false);
        vector<int>dist(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,edges,visited,inrecursion,dist);
            }
        }
        return result;
    }
};