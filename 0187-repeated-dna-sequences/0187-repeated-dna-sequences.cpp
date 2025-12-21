class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>result;
        set<string>t,ans;
        int i=0,j=0;
        while(j<s.size()){
            if(j-i+1==10){
                string p=s.substr(i,10);
                if(t.find(p)!=t.end() ){
                    ans.insert(p);
                }
                else{
                    t.insert(p);
                }
                i++;
            }
            j++;
        }
        for(auto i:ans)result.push_back(i);
        return result;
    }
};