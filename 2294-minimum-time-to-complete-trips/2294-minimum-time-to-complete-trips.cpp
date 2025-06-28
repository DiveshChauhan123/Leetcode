class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(), time.end());
        long long s = 1;
        long long e = 1LL * time[0] * totalTrips;
        
        while (s < e) {
            long long mid = s + (e - s) / 2;
            long long t = 0;
            
            for (int i = 0; i < time.size(); i++) {
                t += mid / time[i];  // ✅ correct logic
            }

            if (t >= totalTrips) {
                e = mid;
            } else {
                s = mid + 1;
            }
        }

        return s; // ✅ 's' will be the minimum time satisfying the condition
    }
};
