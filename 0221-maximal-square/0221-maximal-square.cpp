class Solution {
public:
    int n, m;
    vector<vector<int>>t;
    int solve(vector<vector<char>>& matrix, int i, int j, int& maxi) {
        if (i >= n || j >= m) return 0;
        if(t[i][j]!=-1)return t[i][j];
        int right = solve(matrix, i, j + 1, maxi);
        int down = solve(matrix, i + 1, j, maxi);
        int diagonal = solve(matrix, i + 1, j + 1, maxi);

        if (matrix[i][j] == '1') {
            int curr = 1 + min({right, down, diagonal});
            maxi = max(maxi, curr * curr); // area = side * side
            return t[i][j]=curr;
        } else {
            return t[i][j]=0;
        }
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        t.assign(n,vector<int>(m,-1));
        int maxi = 0;
        solve(matrix, 0, 0, maxi);
        return maxi;
    }
};
