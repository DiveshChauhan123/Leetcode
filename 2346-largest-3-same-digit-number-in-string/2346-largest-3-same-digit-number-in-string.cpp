class Solution {
public:
    string largestGoodInteger(string num) {
        int count=1;
        vector<string>result;
        for(int i=1;i<num.size();i++){
            if(num[i]==num[i-1])count++;
            else{
                count=1;
            }
            if(count==3){
                result.push_back(num.substr(i-2,3));
            }
        }
        sort(result.begin(),result.end());
        if(result.size()==0)return "";
        return result[result.size()-1];
    }
};