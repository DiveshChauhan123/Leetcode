class Solution {
public:
long long solve(int l,int r){
    long long L=1;
    long long R=1;
    long long s=1;
    long long steps=0;
    while(L<=r){
        R=4*L-1;
        long long start=max(L,(long long)l);
        long long end=min(R,(long long)r);
        if(start<=end){
            steps+=(end-start+1)*s;
        }
        L=R+1;
        R=4*L-1;
        s++;
    }
    return steps;
}
    long long minOperations(vector<vector<int>>& queries) {
        long long result=0;
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            result+=(solve(l,r)+1)/2;
        }
        return result;
    }
};