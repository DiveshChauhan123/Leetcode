class Solution {
public:
unordered_set<string>dict;
vector<string>result;
void solve(int i,string curr,string s){
    if(i>=s.size()){
        result.push_back(curr);
        return;
    }
    for(int j=i;j<s.size();j++){
        string temp=s.substr(i,j-i+1);
        if(dict.find(temp)!=dict.end()){
            string p=curr;
            if(!curr.empty()){
                curr+=" ";
            }
            curr+=temp;
            solve(j+1,curr,s);
            curr=p;
        }
    }
}
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        for(string st:wordDict){
            dict.insert(st);
        }
        string curr="";
        solve(0,curr,s);
        return result;
    }
};