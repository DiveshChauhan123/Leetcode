class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int s=1;
        int e=piles[piles.size()-1];
        while(s<e){
            int mid=s+(e-s)/2;
            int th=0;
            for(int i=0;i<piles.size();i++){
                th+=(piles[i]/mid);
                if(piles[i]%mid!=0){
                    th++;
                }
            }
            if(th<=h){
                e=mid;
            }
            else{
                s=mid+1;
            }
        }
        return s;
    }
};