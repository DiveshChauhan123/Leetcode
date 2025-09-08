class Solution {
public:
int t[1001][1002];
int solve(vector<pair<int,int>>&players,int index,int prev){
    if(index>=players.size())return 0;
    if(t[index][prev+1]!=-1)return t[index][prev+1];
    int ans=solve(players,index+1,prev);
    if(prev==-1 || players[index].second>=players[prev].second){
        ans=max(ans,players[index].second+solve(players,index+1,index));
    }
    return t[index][prev+1]=ans;
}
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>>players;
        for(int i=0;i<ages.size();i++){
            players.push_back({ages[i],scores[i]});
        }
        sort(players.begin(),players.end());
        memset(t,-1,sizeof(t));
        return solve(players,0,-1);
    }
};