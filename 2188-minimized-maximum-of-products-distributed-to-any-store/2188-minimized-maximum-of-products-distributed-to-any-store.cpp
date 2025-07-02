class Solution {
public:
    bool possible(int n, vector<int>& quantities, int mid) {
        int storeCount = 0;
        for (int q : quantities) {
            storeCount += (q + mid - 1) / mid;
        }
        return storeCount <= n;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int s = 1;
        int e = *max_element(quantities.begin(), quantities.end());
        int result = e;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (possible(n, quantities, mid)) {
                result = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return result;
    }
};
