class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i=0;
        int j=0;
        int curr_max=INT_MIN;
        int cost=0;
        while(j<s.size()){
            cost+=abs(s[j]-t[j]);
            while(cost>maxCost){
                cost-=abs(s[i]-t[i]);
                i++;
            }
            curr_max=max(curr_max,j-i+1);
            j++;
        }
        return curr_max;
    }
};