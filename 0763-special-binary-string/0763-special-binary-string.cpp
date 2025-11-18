class Solution {
public:
    string makeLargestSpecial(string s) {
        int i=0;
        int count=0;
        vector<string>ans;
        for(int j=0;j<s.size();j++){
            if(s[j]=='1')count++;
            else count--;
            if(count==0){
                ans.push_back("1"+ makeLargestSpecial(s.substr(i+1,j-i-1))+ "0");
                i=j+1;
            }
        }
        sort(ans.begin(),ans.end());
        reverse(ans.begin(),ans.end());
        string res2;
        for(int i=0;i<ans.size();i++)res2+=ans[i];
        return res2;

    }
};