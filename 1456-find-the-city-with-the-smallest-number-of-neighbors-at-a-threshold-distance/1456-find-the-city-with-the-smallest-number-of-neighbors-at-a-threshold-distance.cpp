class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>matrix(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            matrix[i][i]=0;
        }
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            if(wt<=distanceThreshold){
                matrix[u][v]=wt;
                matrix[v][u]=wt;
            }
        }
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(matrix[i][via]+matrix[via][j]<=distanceThreshold){
                        matrix[i][j]=min(matrix[i][via]+matrix[via][j],matrix[i][j]);
                    }
                }
            }
        }int mincity=INT_MAX;
        int index=0;
        for(int i=0;i<n;i++){
            int x=0;
            for(int j=0;j<n;j++){
                if(matrix[i][j]<=distanceThreshold){
                    x++;
                }
            }
            if(x<=mincity){
                mincity=min(mincity,x);
                index=i;
            }
        }
        return index;
    }
};