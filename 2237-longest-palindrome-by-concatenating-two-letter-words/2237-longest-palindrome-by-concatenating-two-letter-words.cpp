class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n=words.size();
        unordered_map<string,int>mp;
        int result=0;
        for(int i=0;i<n;i++){
            string s=words[i];
            string t=words[i];
            reverse(t.begin(),t.end());
            if(mp[t]>0){
                result+=4;
                mp[t]--;
            }
            else{
                mp[s]++;
            }
        }
        for(auto i:mp){
            string x=i.first;
            int count=i.second;
            if(x[0]==x[1] && count>0){
                result+=2;
                break;
            }
        }
        return result;
    }
};