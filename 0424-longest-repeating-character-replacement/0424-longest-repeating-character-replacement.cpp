class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26,0);
        int maxi=0;
        int i=0,j=0;
        for(;j<s.size();j++){
            freq[s[j]-'A']++;
            int max_freq=max(max_freq,freq[s[j]-'A']);
            while((j-i+1)-max_freq>k){
                freq[s[i]-'A']--;
                i++;
            }
            maxi=max(maxi,j-i+1);
        }
        return maxi;
    }
};