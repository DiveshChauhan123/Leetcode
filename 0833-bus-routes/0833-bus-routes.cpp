class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target)return 0;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<routes.size();i++){
            for(auto j:routes[i])mp[j].push_back(i);
        }
        queue<int>q;
        vector<int>visited(routes.size());
        for(auto i:mp[source]){
            q.push(i);
        }
        int buscount=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int route=q.front();
                q.pop();
                for(auto i:routes[route]){
                    if(i==target)return buscount;
                    for(auto neigh:mp[i]){
                        if(!visited[neigh]){
                            visited[neigh]=true;
                            q.push(neigh);
                        }
                    }
                }
            }
            buscount++;
        }
        return -1;
    }
};