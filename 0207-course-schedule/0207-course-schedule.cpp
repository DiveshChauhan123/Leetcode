class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        unordered_map<int,list<int>>mp;
        unordered_map<int,int>indegree;
        for(int i=0;i<n;i++){
            int x=prerequisites[i][0];
            int y=prerequisites[i][1];
            mp[y].push_back(x);
            indegree[x]++;
        }
        int count=0;
        queue<int>q;
        
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
                count++;
            }
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto neigh:mp[x]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                    count++;
                }
            }
        }
        if(count==numCourses){
            return true;;
        }
        return false;
    }
};