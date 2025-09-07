class Solution {
public:
map<vector<int>,int>mp;
int memo(vector<int>& price, vector<vector<int>>& special, vector<int> needs){
    if(mp.count(needs))return mp[needs];
    int n=price.size();
    int mini=0;
    for(int i=0;i<n;i++){
        mini+=price[i]*needs[i];
    }
    for(auto &sp:special){
        vector<int>newneeds=needs;
        bool valid=true;
        for(int i=0;i<n;i++){
            if(newneeds[i]<sp[i]){
                valid=false;
                break;
            }
            newneeds[i]-=sp[i];
        }
        if(valid){
            mini=min(mini,sp[n]+memo(price,special,newneeds));
        }
    }
    return mp[needs]=mini;
}
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return memo(price,special,needs);
    }
};