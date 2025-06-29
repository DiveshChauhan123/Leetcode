class Solution {
public:
    vector<string> partitionString(string s) {
        set<string>st;
        int sizet=1;
        vector<string>result;
        int x=1;
        for(int i=0;i<s.size();i+=x){
            string p=s.substr(i,sizet);
            if(st.find(p)==st.end()){
                st.insert(p);
                result.push_back(p);
                x=1;
            }
            else{
                for(int sizet=2;sizet<=s.size()-i;sizet++){
                    string t=s.substr(i,sizet);
                    if(st.find(t)!=st.end())continue;
                    else{
                        st.insert(t);
                        result.push_back(t);
                        x=sizet;
                        break;
                    }
                }
            }
            sizet=1;
        }
        
        return result;
    }
};