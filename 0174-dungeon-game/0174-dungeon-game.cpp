class Solution {
public:
int t[201][201];
int solve(vector<vector<int>>&dungeon,int i,int j){
    if(i>=dungeon.size() || j>=dungeon[0].size())return INT_MAX;
    if(i==dungeon.size()-1 && j==dungeon[0].size()-1){
        return t[i][j]=(dungeon[i][j]<=0)?-dungeon[i][j]+1:1;
    }
    if(t[i][j]!=-1)return t[i][j];
    int goright=solve(dungeon,i+1,j);
    int goleft=solve(dungeon,i,j+1);
    int min_health=min(goright,goleft)-dungeon[i][j];
    return t[i][j]=(min_health<=0)?1:min_health;
}
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(t,-1,sizeof(t));
        return solve(dungeon,0,0);
    }
};