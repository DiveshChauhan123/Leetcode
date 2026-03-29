class EventManager {
public:
priority_queue<pair<int,int>>pq;
unordered_map<int,int>mp;
    EventManager(vector<vector<int>>& events) {
        for(auto i:events){
            pq.push({i[1],-i[0]});
            mp[i[0]]=i[1];
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        mp[eventId]=newPriority;
        pq.push({newPriority,-eventId});
    }
    
    int pollHighest() {
        while(!pq.empty()){
            auto [pr, negId] = pq.top();
            int id = -negId;

            // lazy deletion
            if(!mp.count(id) || mp[id] != pr){
                pq.pop();
                continue;
            }

            pq.pop();
            mp.erase(id);
            return id;
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */