class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>>mp;
        for(int i=0;i<roads.size();i++){
            mp[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            mp[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        queue<int>pq;
        pq.push(1);
        int mini=INT_MAX;
        vector<int>visited(n+1,0);
        visited[1]=1;
        while(!pq.empty()){
            int node=pq.front();
            pq.pop();
            for(auto [k,f]:mp[node]){
                mini=min(mini,f);
                if(!visited[k]){
                    visited[k]=1;
                    pq.push(k);
                }
            }
        }
        return mini;
    }
};