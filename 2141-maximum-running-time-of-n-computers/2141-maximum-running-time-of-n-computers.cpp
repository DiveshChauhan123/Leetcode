class Solution {
public:
    typedef long long ll;
    bool canRun(vector<int>&batteries,int n,ll mid){
        ll target_minutes=mid*n;

        for(int i=0;i<batteries.size();i++){
            // min bcoz ith battery can only contribute mid mins :)
            target_minutes-=min((ll) batteries[i],mid);

            if(target_minutes<=0) return true;
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        ll l=*min_element(begin(batteries),end(batteries));

        ll sum=accumulate(begin(batteries),end(batteries),0LL);
        ll r=sum/n;

        ll ans=0;

        while(l<=r){
            ll mid=l+(r-l)/2;

            if(canRun(batteries,n,mid)){
                ans=mid;
                l=mid+1;
            } else{
                r=mid-1;
            }
        }
        return ans;
    }
};