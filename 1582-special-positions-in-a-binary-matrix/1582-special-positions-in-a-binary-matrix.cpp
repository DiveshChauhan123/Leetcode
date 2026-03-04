class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int count=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0)continue;
                bool a=true;
                for(int k=0;k<mat.size();k++){
                    if(mat[k][j]==1 && i!=k){
                        a=false;
                        break;
                    }
                }
                for(int k=0;k<mat[0].size();k++){
                    if(mat[i][k]==1 && j!=k){
                        a=false;
                        break;
                    }
                }
                if(a)count++;
            }
        }
        return count;
    }
};