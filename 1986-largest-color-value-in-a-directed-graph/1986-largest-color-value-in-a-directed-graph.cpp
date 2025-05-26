class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        unordered_map<int,list<int>>mp;
        vector<int>indegree(colors.size(),0);
        for(auto &i:edges){
            int u=i[0];
            int v=i[1];
            mp[u].push_back(v);
            indegree[v]++;
        }
        vector<vector<int>>t(colors.size(),vector<int>(26,0));
        queue<int>q;
        for(int i=0;i<colors.size();i++){
            if(indegree[i]==0){
                q.push(i);
                t[i][colors[i]-'a']=1;
            }
        }
        int ans=0;
        int countnodes=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            countnodes++;
            ans=max(ans,t[u][colors[u]-'a']);
            for(auto &v:mp[u]){
                for(int i=0;i<26;i++){
                    t[v][i]=max(t[v][i],t[u][i]+(colors[v]-'a'==i));
                }
                indegree[v]--;
                if(indegree[v]==0)q.push(v);
            }
        }
        if(countnodes!=colors.size())return -1;
        return ans;
    }
};