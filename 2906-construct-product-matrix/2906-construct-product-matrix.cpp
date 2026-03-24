class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>arr(n*m),prefix(n*m,1),suffix(n*m,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[i*m+j]=grid[i][j]%12345;
            }
        }
        //prefix array;
        prefix[0]=arr[0];
        suffix[n*m-1]=arr[n*m-1];
        for(int i=1;i<n*m;i++){
            prefix[i]=(prefix[i-1]*arr[i])%12345;
        }
        for(int i=n*m-2;i>=0;i--){
            suffix[i]=(suffix[i+1]*arr[i])%12345;
        }
        vector<vector<int>>p(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    p[i][j]=suffix[1]%12345;
                    continue;
                }
                if(i==n-1 && j==m-1){
                    p[i][j]=prefix[n*m-2]%12345;
                    continue;
                }
                p[i][j]=(prefix[i*m+j-1]*suffix[i*m+j+1])%12345;
            }
        }
        return p;
    }
};