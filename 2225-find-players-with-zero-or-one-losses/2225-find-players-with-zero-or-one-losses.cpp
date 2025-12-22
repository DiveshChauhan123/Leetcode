class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>w,l;
        set<int>wi,lo;
        for(int i=0;i<matches.size();i++){
            int x=matches[i][0];
            int y=matches[i][1];
            l[y]++;
            w[x]++;
        }
        for(int i=0;i<matches.size();i++){
            int x=matches[i][0];
            int y=matches[i][1];
            if(l[x]==0){
                wi.insert(x);
            }
            if(l[x]==1){
                lo.insert(x);
            }
            if(l[y]==0)wi.insert(y);
            if(l[y]==1){
                lo.insert(y);
            }
        }
        vector<vector<int>>ans(2);
        for(auto i:wi)ans[0].push_back(i);
        for(auto i:lo)ans[1].push_back(i);
        return ans;
    }
};
//hcl 12lpa
//q3 technologies 15lpa
//simens 16lpa