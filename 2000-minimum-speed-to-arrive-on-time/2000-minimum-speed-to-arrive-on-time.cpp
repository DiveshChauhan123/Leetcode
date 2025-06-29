class Solution {
public:
    bool canArriveOnTime(vector<int>& dist, double hour, int speed) {
        double totalTime = 0.0;
        int n = dist.size();
        for (int i = 0; i < n; ++i) {
            double time = (double)dist[i] / speed;
            if (i != n - 1) {
                totalTime += ceil(time);  // round up for all except last
            } else {
                totalTime += time;  // last train: can be fractional
            }
            if (totalTime > hour) return false;  // prune early
        }
        return totalTime <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left = 1;
        int right = 1e7;
        int answer = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canArriveOnTime(dist, hour, mid)) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return answer;
    }
};
