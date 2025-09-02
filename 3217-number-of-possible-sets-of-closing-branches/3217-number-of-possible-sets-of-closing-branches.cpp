class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int result=0;
        for(int set=0;set<(1<<n);set++){
            vector<vector<int>>graph(n,vector<int>(n,1e9));
            bool ok=true;
            for(int i=0;i<roads.size();i++){
                int u=roads[i][0];
                int v=roads[i][1];
                int wt=roads[i][2];
                if((set>>u &1) && (set>>v &1)){
                    graph[u][v]=min(graph[u][v],wt);
                    graph[v][u]=min(graph[v][u],wt);
                }
            }

            for(int i=0;i<n;i++){
                graph[i][i]=0;
            }

            //apply flyod warshall algorithm

            for(int via=0;via<n;via++){
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        graph[i][j]=min(graph[i][j],graph[i][via]+graph[via][j]);
                    }
                }
            }

            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j)continue;
                    if((set>>i &1) && (set>>j &1)){
                        if(graph[i][j]>maxDistance){
                            ok=false;
                        }
                    }
                }
            }
            if(ok)result++;
        }
        return result;
    }
};