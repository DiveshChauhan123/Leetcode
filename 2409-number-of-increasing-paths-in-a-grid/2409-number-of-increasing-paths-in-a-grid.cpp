class Solution {
public:
int n,m;
int t[1001][1001];
long long MOD=1e9+7;
int solve(vector<vector<int>>& grid,int a,int b){
    int answer=1;
    int dx[]={0,-1,0,1};
    int dy[]={1,0,-1,0};
    if(t[a][b]!=-1)return t[a][b];
    for(int i=0;i<4;i++){
        int x=a+dx[i];
        int y=b+dy[i];
        if(x>=0 && x<n && y>=0 && y<m && grid[x][y]>grid[a][b]){
            answer=(answer+solve(grid,x,y))%MOD;
        }
    }
    return t[a][b]=answer%MOD;
}
    int countPaths(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(t,-1,sizeof(t));
        int result=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result=(result+solve(grid,i,j))%MOD;
            }
        }
        return result;
    }
};