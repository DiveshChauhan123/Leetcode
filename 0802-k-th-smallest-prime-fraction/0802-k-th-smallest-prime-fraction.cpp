class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<tuple<double,int,int>> pq;

        int n = arr.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                double frac = (double)arr[i] / arr[j];
                if(pq.size() == k) {
                    if(get<0>(pq.top()) > frac) {
                        pq.pop();
                        pq.push({frac, arr[i], arr[j]});
                    }
                } else {
                    pq.push({frac, arr[i], arr[j]});
                }
            }
        }

        return {get<1>(pq.top()), get<2>(pq.top())};
    }
};
