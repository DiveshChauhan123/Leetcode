class Solution {
public:
const int MOD=1e9+7;
    int N, M, K;
    int t[51][101][51];

    int solve(int index, int maxval, int searchcost) {
        if (index >= N) {
            return searchcost == K ? 1 : 0;
        }
        if (t[index][maxval][searchcost] != -1) 
            return t[index][maxval][searchcost];

        int result = 0;
        for (int i = 1; i <= M; i++) {
            if (i > maxval) {
                result =(result + solve(index + 1, i, searchcost + 1))%MOD;
            } else {
                result =(result+ solve(index + 1, maxval, searchcost))%MOD;
            }
        }
        return t[index][maxval][searchcost] = result;
    }

    int numOfArrays(int n, int m, int k) {
        N = n, M = m, K = k;
        memset(t, -1, sizeof(t));
        return solve(0, 0, 0);
    }
};
