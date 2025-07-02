class Solution {
public:
bool possible(vector<int>&candies,int mid,long long k){
    long long count=0;
    for(int i=0;i<candies.size();i++){
        count+=candies[i]/mid;
    }
    return count>=k;
}
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        int result=0;
        int s=1;
        int e=*max_element(candies.begin(),candies.end());
        while(s<=e){
            int mid=s+(e-s)/2;
            if(possible(candies,mid,k)){
                s=mid+1;
                result=mid;
            }
            else{
                e=mid-1;
            }
        }
        return result;
    }
};