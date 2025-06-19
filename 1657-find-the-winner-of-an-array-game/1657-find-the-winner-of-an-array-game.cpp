class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int x=0;
        int n=arr.size();
        int prev=arr[0];
        for(int i=1;i<n;i++){
            if(prev>arr[i]){
                x++;
            }
            else{
                prev=arr[i];
                x=1;
            }
            if(x==k)return prev;
        }
        return prev;
    }
};