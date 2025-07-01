class Solution {
public:
    int n, m;
    int t[2001][2001];

    bool solve(string& s, string& p, int i, int j) {
        if (i == n && j == m) return true;
        if (j == m) return false;
        if (i == n) {
            for (int k = j; k < m; ++k) {
                if (p[k] != '*') return false;
            }
            return true;
        }

        if (t[i][j] != -1) return t[i][j];

        if (s[i] == p[j] || p[j] == '?') {
            return t[i][j] = solve(s, p, i + 1, j + 1);
        }

        if (p[j] == '*') {
            // * matches 0 characters or 1 character
            return t[i][j] = solve(s, p, i + 1, j) || solve(s, p, i, j + 1);
        }

        return t[i][j] = false;
    }

    bool isMatch(string s, string p) {
        n = s.size();
        m = p.size();
        memset(t, -1, sizeof(t));
        return solve(s, p, 0, 0);
    }
};
