class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i-j].push_back(grid[i][j]);
            }
        }
        for(auto &entry:mp){
            if(entry.first<0){
                sort(entry.second.begin(),entry.second.end());
            }
            else{
                sort(entry.second.rbegin(),entry.second.rend());
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j]=mp[i-j].front();
                mp[i-j].erase(mp[i-j].begin());
            }
        }
        return grid;
    }
};