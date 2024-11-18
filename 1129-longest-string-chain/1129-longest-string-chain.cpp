class Solution {
public:
    bool isSubsequence(string &a, string &b){
        int i=0;
            int j=0;
            while(i<a.size()&&j<b.size()){
                if(a[i]==b[j])
                    i++;
                j++;
            }

            if(i==a.size())
                return true;
        
        return false;
        
    }
    int recurse(vector<string>& words, int idx, int prev,vector<vector<int>> &dp){
        if(idx==words.size())
            return 0;
        if(dp[idx][prev+1]!=-1)
            return dp[idx][prev+1];
        if(prev==-1){
            return dp[idx][prev+1]= max(recurse(words,idx+1,prev,dp), 1+recurse(words,idx+1,idx,dp));
        }
        int maxi=0;
        if(words[prev].size()==words[idx].size()-1&&isSubsequence(words[prev],words[idx])){
                maxi= 1 + recurse(words,idx+1,idx,dp);
        }
        else if(words[prev].size()==words[idx].size()-2)
            return dp[idx][prev+1]=0;
        return dp[idx][prev+1]=max(maxi,recurse(words,idx+1,prev,dp));
        
    }
    
    static bool comparator(string &a, string &b){
        return a.size()<b.size();
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comparator);
        vector<vector<int>> dp(words.size(),vector<int>(words.size()+1,-1));
        return recurse(words,0,-1,dp);
    }
};