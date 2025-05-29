class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        vector<int>result;
        for(int i=0;i<mat[0].size()+mat.size()-1;i++){
            vector<int>x=mp[i];
            if(i%2==0){
                reverse(x.begin(),x.end());
            }
            for(int i=0;i<x.size();i++){
                result.push_back(x[i]);
            }

        }
        return result;
    }
};