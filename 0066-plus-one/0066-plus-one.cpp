class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int count=1;
        vector<int>ans;
        int n=digits.size()-1;
        while(count==1 && n>=0){
            if(digits[n]+1==10){
                digits[n]=0;
                count=1;
                n--;
            }
            else{
                digits[n]=digits[n]+1;
                count=0;
            }
        }
        if(count==1){
            ans.push_back(count);
            for(int i=0;i<digits.size();i++){
                ans.push_back(digits[i]);
            }
            return ans;
        }
        return digits;
    }
};