class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string>seen,repeated;
        vector<string>result;
        int i=0,j=0;
        while(j<s.size()){
            if(j-i+1==10 ){
                string p=s.substr(i,10);
                if(!seen.insert(p).second){
                    repeated.insert(p);
                }
                i++;
            }
            j++;
        }
        for(auto i:repeated)result.push_back(i);
        return result;
    }
};