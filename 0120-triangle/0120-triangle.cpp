class Solution {
public:
int n;
vector<vector<int>>t;
int solve(vector<vector<int>>& triangle,int row,int index){
    if(row==n-1)return triangle[row][index];
    if(t[row][index]!=-1)return t[row][index];
    int left=solve(triangle,row+1,index);
    int right=solve(triangle,row+1,index+1);
    return t[row][index]=triangle[row][index]+min(left,right);
}
    int minimumTotal(vector<vector<int>>& triangle) {
        n=triangle.size();
        t.assign(n, vector<int>(n, -1));
        return solve(triangle,0,0);
    }
};