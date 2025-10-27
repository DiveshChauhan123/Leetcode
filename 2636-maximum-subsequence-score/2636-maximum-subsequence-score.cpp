class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>ans;
        int n=nums1.size();
        for(int i=0;i<nums1.size();i++){
            ans.push_back({nums1[i],nums2[i]});
        }
        auto lamda=[&](auto &p1 ,auto &p2){
            return p1.second>p2.second;
        };
        sort(ans.begin(),ans.end(),lamda);
        priority_queue<int,vector<int>,greater<int>>pq;
        long long Ksum = 0;
        
        for(int i = 0; i<=k-1; i++) {
            
            Ksum += ans[i].first;
            pq.push(ans[i].first);
            
        }
        
        long long result = Ksum * ans[k-1].second;
        
        for(int i = k; i<n; i++) {
            
            //taking minimum as vec[i].second
            Ksum += ans[i].first - pq.top();
            pq.pop();
            
            pq.push(ans[i].first);
            
            result = max(result, Ksum * ans[i].second);
            
        }
        
        return result;
    }
};