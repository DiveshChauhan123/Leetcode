class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        vector<bool>result(n,0);
        for(int i=0;i<n;i++){
            int x=fruits[i];
            for(int j=0;j<n;j++){
                if(baskets[j]>=fruits[i] && result[j]==false){
                    result[j]=true;
                    break;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(result[i]==false){
                ans++;
            }
        }
        return ans;
    }
};