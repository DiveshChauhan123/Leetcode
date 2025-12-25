class Solution {
public:
long long reflect(long long x) {
        long long r = 0;
        while (x > 0) {
            r = (r << 1) | (x & 1);
            x >>= 1;
        }
        return r;
    }
    vector<int> sortByReflection(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            long long ra = reflect(a);
            long long rb = reflect(b);
            if (ra != rb) return ra < rb;
            return a < b;
        });
        return nums;
    }
};