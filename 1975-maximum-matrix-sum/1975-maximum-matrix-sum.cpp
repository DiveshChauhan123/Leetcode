class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int mini_p=INT_MAX;
        int mini_n=INT_MIN;
        long long sum=0;
        int negative=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]<0){
                    negative++;
                    mini_n=max(mini_n,matrix[i][j]);
                }
                else{
                    mini_p=min(mini_p,matrix[i][j]);
                }
            }
        }
        for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(matrix[i][j]>0)sum+=matrix[i][j];
                    else{
                        sum=sum-1*matrix[i][j];
                    }
                }
            }
        if(negative%2==0){
            return sum;
        }
        if(-1*mini_n<mini_p){
            sum=sum+2*mini_n;
        }
        else if(-1*mini_n>=mini_p){
            sum=sum-2*mini_p;
        }
        return sum;
    }
};