class Solution {
public:
    // Check if we can place 'm' balls with at least 'mid' distance apart
    bool possible(vector<int>& position, int m, int mid) {
        int count = 1;
        int last = position[0];
        for (int i = 1; i < position.size(); i++) {
            if (position[i] - last >= mid) {
                count++;
                last = position[i];
            }
            if (count >= m) return true;
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int s = 1;
        int e = position.back() - position.front(); // maximum possible distance
        int result = 0;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (possible(position, m, mid)) {
                result = mid;
                s = mid + 1; // try for bigger distance
            } else {
                e = mid - 1;
            }
        }

        return result;
    }
};
