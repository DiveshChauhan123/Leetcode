class Solution {
public:
int memo[50001];
int currentnextjob(vector<vector<int>>&ans,int l,int target){
    int r=ans.size()-1;
    int result=r+2;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(ans[mid][0]>=target){
            result=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return result;
}
int solve(vector<vector<int>>&ans,int index){
    if(index>=ans.size())return 0;
    if(memo[index]!=-1)return memo[index];
    int nextjob=currentnextjob(ans,index+1,ans[index][1]);
    int take=ans[index][2]+solve(ans,nextjob);
    int nottake=solve(ans,index+1);
    return memo[index]=max(take,nottake);
}
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        memset(memo,-1,sizeof(memo));
        vector<vector<int>>ans(n,vector<int>(3));
        for(int i=0;i<n;i++){
            ans[i][0]=startTime[i];
            ans[i][1]=endTime[i];
            ans[i][2]=profit[i];
        }
        sort(ans.begin(),ans.end());
        return solve(ans,0);
    }
};