class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>>graph(26,vector<long long>(26,INT_MAX));
        for(int i=0;i<original.size();i++){
            int u=original[i]-'a';
            int v=changed[i]-'a';
            graph[u][v]=min(graph[u][v],1LL*cost[i]);
        }
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                for(int k=0;k<26;k++){
                    graph[j][k]=min(graph[j][k],graph[j][i]+graph[i][k]);
                }
            }
        }
        long long ans=0;
        for(int i=0;i<source.size();i++){
            if(source[i]==target[i])continue;

            int u=source[i]-'a';
            int v=target[i]-'a';
            if(graph[u][v]==INT_MAX)return -1;
            ans+=graph[u][v];
        }
        return ans;
    }
};