class Solution {
public:
    bool good(int num) {
        bool changed = false;

        while (num) {
            int d = num % 10;

            if (d == 3 || d == 4 || d == 7)
                return false;

            if (d == 2 || d == 5 || d == 6 || d == 9)
                changed = true;

            num /= 10;
        }

        return changed;
    }

    int rotatedDigits(int n) {
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (good(i))
                ans++;
        }

        return ans;
    }
};