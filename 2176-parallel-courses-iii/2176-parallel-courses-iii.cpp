class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int>inorder(n+1);
        unordered_map<int,vector<int>>mp;
        for(auto i:relations){
            mp[i[0]].push_back(i[1]);
            inorder[i[1]]++;
        }
        int count=0;
        queue<int>q;
        vector<int>ans(n+1,0);
        for(int i=1;i<=n;i++){
            if(inorder[i]==0){
                q.push(i);
                ans[i]=time[i-1];
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto neigh:mp[node]){
                inorder[neigh]--;
                if(inorder[neigh]==0){
                    q.push(neigh);
                }
                ans[neigh]=max(ans[neigh],ans[node]+time[neigh-1]);
            }
        }
        return *max_element(ans.begin(),ans.end());
    }
};