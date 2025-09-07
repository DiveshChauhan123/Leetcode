class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        int x=1;
        if(n%2==0){
            while(n!=0){
                ans.push_back(x);
                ans.push_back(-1*x);
                x++;
                n-=2;
            }
        }
        else{
            ans.push_back(0);
            n--;
            while(n!=0){
                ans.push_back(x);
                ans.push_back(-1*x);
                x++;
                n-=2;
            }
        }
        return ans;
    }
};