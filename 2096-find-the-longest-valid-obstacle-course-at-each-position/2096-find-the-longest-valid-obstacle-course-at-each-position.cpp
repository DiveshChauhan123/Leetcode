class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int>dp;
        vector<int>result(obstacles.size(),0);
        for(int i=0;i<obstacles.size();i++){
            int idx=upper_bound(dp.begin(),dp.end(),obstacles[i])-dp.begin();
            if(idx==dp.size()){
                dp.push_back(obstacles[i]);
            }
            else{
                dp[idx]=obstacles[i];
            }
            result[i]=idx+1;
        }
        return result;
    }
};