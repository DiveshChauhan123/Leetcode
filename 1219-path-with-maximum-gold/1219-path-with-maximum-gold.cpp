class Solution {
public:
int count=INT_MIN;
int n,m;
void solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&visited,int score){
    count=max(count,score);
    int dx[]={0,-1,0,1};
    int dy[]={1,0,-1,0};
    for(int k=0;k<4;k++){
        int x=i+dx[k];
        int y=j+dy[k];
        if(x>=0 && x<n && y>=0 && y<m && !visited[x][y] && grid[x][y]!=0){
            visited[x][y]=1;
            solve(x,y,grid,visited,score+grid[x][y]);
            visited[x][y]=0;
        }
    }
}
    int getMaximumGold(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    visited[i][j]=1;
                    solve(i,j,grid,visited,grid[i][j]);
                    visited[i][j]=0;
                }
            }
        }
        return count==INT_MIN?0:count;
    }
};