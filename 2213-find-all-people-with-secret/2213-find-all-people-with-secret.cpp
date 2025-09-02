class Solution {
public:
void dfs(int node,vector<int>&visited,unordered_map<int,vector<pair<int,int>>>&mp,int t,set<int>&result){
    for(auto i:mp[node]){
        int neigh=i.first;
        int time=i.second;
        if(visited[neigh]>time && time>=t){
            visited[neigh]=time;
            dfs(neigh,visited,mp,time,result);
        }
    }
}
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map<int,vector<pair<int,int>>>mp;
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        for(int i=0;i<meetings.size();i++){
            int u=meetings[i][0];
            int v=meetings[i][1];
            int wt=meetings[i][2];
            mp[u].push_back({v,wt});
            mp[v].push_back({u,wt});
        }
        set<int>result;
        vector<int>visited(n,INT_MAX);
        mp[0].push_back({firstPerson,0});
        mp[firstPerson].push_back({0,0});
        dfs(firstPerson,visited,mp,0,result);
        vector<int>ans;
        for(int i=0;i<visited.size();i++){
            if(visited[i]!=INT_MAX){
                ans.push_back(i);
            }
        }
        return ans;
    }
};