class Solution {
public:
    int maximum69Number (int num) {
        string s=to_string(num);
        for(int i=0;i<s.size();i++){
            if(s[i]=='6'){
                s[i]='9';
                break;
            }
        }
        int x=1;
        for(int i=1;i<s.size();i++){
            x*=10;
        }
        int ans=0;
        for(int i=0;i<s.size();i++){
            int nums=s[i]-'0';
            if(x>0){
                ans+=(nums*x);
                x/=10;
            }
        }
        return ans;
    }
};