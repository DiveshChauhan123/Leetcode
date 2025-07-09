class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int>v;
        if(startTime[0]!=0){
            v.push_back(startTime[0]);
        }
        for(int i=1;i<n;i++){
            v.push_back(startTime[i]-endTime[i-1]);
        }
        if(endTime[n-1]!=eventTime){
            v.push_back(eventTime-endTime[n-1]);
        }
        int n1=v.size();
        int i=0;
        int j=0;
        k++;
        long long ans=0;
        long long sum=0;
        while(j<n1){
            sum+=v[j];
           while(i<n1&&j-i+1>k){
               sum-=v[i];
               i++;
           }
            ans=max(ans,sum);
            j++;
        }
        return ans;
    }
};