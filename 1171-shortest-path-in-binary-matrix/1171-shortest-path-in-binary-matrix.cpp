class Solution {
public:
vector<vector<int>>dist={{1,1},{0,1},{1,0},{0,-1},{-1,0},{-1,-1},{1,-1},{-1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]!=0)return -1;
        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0]=1;
        int level=0;
        auto check=[&](int x,int y){
            return x>=0 && x<n && y>=0 && y<m;
        };
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto i=q.front();
                q.pop();
                int x=i.first;
                int y=i.second;
                if(x==n-1 && y==m-1)return level+1;
                for(auto dir:dist){
                    int x_=x+dir[0];
                    int y_=y+dir[1];
                    if(check(x_,y_) && grid[x_][y_]==0){
                        q.push({x_,y_});
                        grid[x_][y_]=1;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};