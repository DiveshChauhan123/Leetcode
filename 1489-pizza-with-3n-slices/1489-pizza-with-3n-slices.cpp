// class Solution {
// public:
// int t[501][170];
// int solve(vector<int>&slices,int index,int size,int p){
//     if(p==0)return 0;
//     if(index>size)return -1e9;
//     if(t[index][p]!=-1)return t[index][p];
//     int nottake=solve(slices,index+1,size,p);
//     int take=slices[index]+solve(slices,index+2,size,p-1);
//     return t[index][p]=max(take,nottake);
// }
//     int maxSizeSlices(vector<int>& slices) {
//         int m=slices.size()/3;
//         memset(t,-1,sizeof(t));
//         return max(solve(slices,0,slices.size()-2,m),solve(slices,1,slices.size()-1,m));
//     }
// };
class Solution {
public:
    int t[501][170];

    int solve(vector<int>& slices, int index, int end, int p) {
        if (p == 0) return 0;
        if (index > end) return -1000000000; // invalid path
        if (t[index][p] != -1) return t[index][p];

        int nottake = solve(slices, index+1, end, p);
        int take = slices[index] + solve(slices, index+2, end, p-1);

        return t[index][p] = max(take, nottake);
    }

    int maxSizeSlices(vector<int>& slices) {
        int m = slices.size();
        int k = m / 3;

        // Case 1: exclude last slice
        memset(t, -1, sizeof(t));
        int case1 = solve(slices, 0, m-2, k);

        // Case 2: exclude first slice
        memset(t, -1, sizeof(t));
        int case2 = solve(slices, 1, m-1, k);

        return max(case1, case2);
    }
};
