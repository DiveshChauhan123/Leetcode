class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>curr;
        int i=0;
        int j=i+1;
        while(i<nums.size()-2 && j<nums.size()-1){
          
                if(abs(nums[i]-nums[j+1])<=k){
                    curr.push_back(nums[i]);
                    curr.push_back(nums[j]);
                    curr.push_back(nums[j+1]);
                    ans.push_back(curr);
                    curr.clear();
                    i=j+2;
                    j=i+1;
                }
               
            
            else{
                i=i+1;
                j=j+1;
            }
        }
        int x=ans.size()*3;
        if(x==nums.size()){
            return ans;
        }
        ans.clear();
        return ans;
    
    }
};