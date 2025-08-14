class Solution {
public:
    string largestGoodInteger(string num) {
        int count=1;
        char maxdigit='\0';
        for(int i=1;i<num.size();i++){
            if(num[i]==num[i-1])count++;
            else{
                count=1;
            }
            if(count==3){
                maxdigit=max(maxdigit,num[i]);
            }
        }
        if(maxdigit=='\0')return "";
        return string(3,maxdigit);
    }
};