class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n=apple.size();
        int m=capacity.size();
        int sum1=accumulate(apple.begin(),apple.end(),0);
        sort(capacity.begin(),capacity.end());
        int sum=0;
        int count=0;
        for(int i=m-1;i>=0;i--){
            sum+=capacity[i];
            count++;
            if(sum>=sum1){
                return count;
            }
        }
        return count;
    }
};