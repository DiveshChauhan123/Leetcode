class Solution {
public:
bool allzeros(vector<int>&counter){
    for(int i=0;i<26;i++){
        if(counter[i]!=0)return false;
    }
    return true;
}
    vector<int> findAnagrams(string s, string p) {
        vector<int>counter(26,0);
        for(char c:p)counter[c-'a']++;
        int i=0;
        int j=0;
        vector<int>result;
        while(j<s.size()){
            counter[s[j]-'a']--;
            if(j-i+1==p.size()){
                if(allzeros(counter)){
                    result.push_back(i);
                }
                counter[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return result;
    }
};