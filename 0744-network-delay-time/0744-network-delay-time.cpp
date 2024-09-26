class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int ,list<pair<int,int>>>mp;
        for(int i=0;i<times.size();i++){
            int a=times[i][0];
            int b=times[i][1];
            int c=times[i][2];
            mp[a].push_back({b,c});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n+1);
        dist[0]=-1;
        for(int i=1;i<=n;i++){
            dist[i]=1e9;
        } 
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto i=pq.top();
            int distance=i.first;
            int adj=i.second;
            pq.pop();
            for(auto j:mp[adj]){
                int x=j.first;
                int y=j.second;
                if(distance+y<dist[x]){
                    dist[x]=distance+y;
                    pq.push({dist[x],x});
                }
            }
        }
        int d=*max_element(dist.begin(),dist.end());
        if(d==1e9)return -1;
        return d;
    }
};