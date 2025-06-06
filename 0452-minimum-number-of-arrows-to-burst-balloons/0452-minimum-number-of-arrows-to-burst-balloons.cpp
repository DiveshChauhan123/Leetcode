class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int x=points[0][0];
        int y=points[0][1];
        int steps=1;
        for(int i=1;i<points.size();i++){
            int l=points[i][0];
            int r=points[i][1];
            if(x<=l && l<=y){
                x=min(x,l);
                y=min(y,r);
            }
            else{
                x=l,y=r;
                steps++;
            }
        }
        return steps;
    }
};