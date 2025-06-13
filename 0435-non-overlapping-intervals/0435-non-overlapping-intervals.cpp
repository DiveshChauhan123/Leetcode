class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        int count=0;
        int start=intervals[0][0];
        int end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            int x=intervals[i][0];
            int y=intervals[i][1];
            
            if(end>x){
                count++;
            }
            else{
                start=x;
                end=y;
            }
        }
        return count;
    }
};