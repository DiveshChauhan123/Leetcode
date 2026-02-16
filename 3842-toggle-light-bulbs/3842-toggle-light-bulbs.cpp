class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int>bulb(101,0);
        for(int i=0;i<bulbs.size();i++){
            bulb[bulbs[i]]=(bulb[bulbs[i]]==0?1:0);
        }
        vector<int>result;
        for(int i=1;i<=100;i++){
            if(bulb[i])result.push_back(i);
        }
        return result;
    }
};