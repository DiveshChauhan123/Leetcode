class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        queue<int>q;
        q.push(0);
        int steps=0;
        vector<int>visited(arr.size(),0);
        visited[0]=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int curr=q.front();
                q.pop();
                int left=curr-1;
                int right=curr+1;
                if(curr==arr.size()-1)return steps;
                if(left>=0 && visited[left]==0){
                    q.push(left);
                    visited[left]=1;
                }
                if(right<=arr.size()-1 && visited[right]==0){
                    q.push(right);
                    visited[right]=1;
                }
                for(auto i:mp[arr[curr]]){
                    if(visited[i]==0){
                        q.push(i);
                        visited[i]=1;
                    }
                }
                mp.erase(arr[curr]);
            }
            steps++;
            
        }
        return steps;
    }
};