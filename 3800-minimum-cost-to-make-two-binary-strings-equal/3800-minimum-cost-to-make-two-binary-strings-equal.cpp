class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        int a = 0, b = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0' && t[i] == '1') a++;
            else if (s[i] == '1' && t[i] == '0') b++;
        }

        long long p = min(a, b);
        long long r = abs(a - b);
        long long pairC=p*min(2*flipCost,swapCost);
        long long other=r/2*min(2*flipCost,swapCost+crossCost);
        long long end=(r%2)*flipCost;
        return pairC+other+end;
    }
};
