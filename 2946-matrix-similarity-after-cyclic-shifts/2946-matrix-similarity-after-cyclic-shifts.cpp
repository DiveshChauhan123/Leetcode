class Solution {
public:
void rotate(vector<vector<int>>& nums, int k,int i) {
    int m = nums.size();
    int n = nums[0].size();

    k %= n;

    

        vector<int> temp(n);

        if (i % 2 == 0) {  
            // even row → left rotate
            for (int j = 0; j < n; j++) {
                temp[j] =nums[i][(j + k) % n];
            }
        } 
        else {  
            // odd row → right rotate
            for (int j = 0; j < n; j++) {
                temp[(j + k) % n] = nums[i][j];
            }
        }

        nums[i] = temp;
    
}
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>>nums=mat;
        for(int i=0;i<mat.size();i++){
            rotate(nums,k,i);
        }
        if(nums==mat)return true;
        return false;
    }
};