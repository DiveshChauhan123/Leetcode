class Solution {
public:
void dfs(int x,int y,vector<vector<char>>& grid,vector<vector<int>>&visited){
    visited[x][y]=1;
    int dx[]={1,0,-1,0};
    int dy[]={0,-1,0,1};
    for(int i=0;i<4;i++){
        int newx=x+dx[i];
        int newy=y+dy[i];
        if(newx>=0 && newx<grid.size() && newy>=0 && newy<grid[0].size() && visited[newx][newy]==0 && grid[newx][newy]=='1'){
            dfs(newx,newy,grid,visited);
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && grid[i][j]=='1'){
                    dfs(i,j,grid,visited);
                    count++;
                }
            }
        }
        return count;
    }
};