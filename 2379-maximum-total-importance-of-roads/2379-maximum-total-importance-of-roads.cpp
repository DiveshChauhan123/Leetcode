class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<roads.size();i++){
            mp[roads[i][0]].push_back(roads[i][1]);
            mp[roads[i][1]].push_back(roads[i][0]);
        }
        vector<int>nodes;
        unordered_map<int,int>ap;
        vector<int>visited(n);
        for(auto &p : mp){
            visited[p.first]=1;
            nodes.push_back(p.first);
        }
        sort(nodes.begin(), nodes.end(), [&](int a, int b) {
            return mp[a].size() < mp[b].size();
        });
        int x=1;
        for(int i=0;i<visited.size();i++){
            if(!visited[i]){
                ap[i]=x;
                x++;
            }
        }
        for(int i=0;i<nodes.size();i++){
            ap[nodes[i]]=x;
            x++;
        }
        long long result=0;
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int a=ap[u];
            int b=ap[v];
            result+=(a+b);
        }
        return result;
    }
};