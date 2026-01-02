class Solution {
public:
    int repeatedNTimes(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (i+1 < n && a[i] == a[i+1]) return a[i];
        if (i+2 < n && a[i] == a[i+2]) return a[i];
        if (i+3 < n && a[i] == a[i+3]) return a[i];
    }
    return -1;
}

};