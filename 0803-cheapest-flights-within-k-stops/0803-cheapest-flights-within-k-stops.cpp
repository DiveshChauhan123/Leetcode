class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>result(n,INT_MAX);
        result[src]=0;
        unordered_map<int,vector<pair<int,int>>>mp;
        for(int i=0;i<flights.size();i++){
            mp[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        queue<pair<int,int>>pq;
        pq.push({src,0});
        while(!pq.empty() && k>=0){
            int size=pq.size();
            while(size--){
                int node=pq.front().first;
                int cost=pq.front().second;
                pq.pop();
                for(auto [neigh,weight]:mp[node]){
                    if(result[neigh]>cost+weight){
                        result[neigh]=cost+weight;
                        pq.push({neigh,result[neigh]});
                    }
                }
            }
            k--;
        }
        return result[dst]==INT_MAX?-1:result[dst];
    }
};