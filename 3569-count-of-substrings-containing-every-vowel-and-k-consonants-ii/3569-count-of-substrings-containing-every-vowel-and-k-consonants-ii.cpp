class Solution {
public:
    bool isVowel(char c) {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }

    long long countOfSubstrings(string word, int k) {
        int n=word.size();
        unordered_map<char,int>mp;
        int lastindex=n;
        vector<int>nextcons(n);
        for(int i=n-1;i>=0;i--){
            nextcons[i]=lastindex;
            if(!isVowel(word[i])){
                lastindex=i;
            }
        }
        long long count=0;
        int consonants=0;
        int i=0,j=0;
        while(j<n){
            if(isVowel(word[j]))mp[word[j]]++;
            else{
                consonants++;
            }
            while(consonants>k){
                if(isVowel(word[i])){
                    mp[word[i]]--;
                    if(mp[word[i]]==0){
                        mp.erase(word[i]);
                    }
                }
                else{
                    consonants--;
                }
                i++;
            }
            while(mp.size()==5 && consonants==k){
                int idx=nextcons[j];
                count+=(idx-j);
                if(isVowel(word[i])){
                    mp[word[i]]--;
                    if(mp[word[i]]==0){
                        mp.erase(word[i]);
                    }
                }
                else{
                    consonants--;
                }
                i++;
            }
            j++;
        }
        return count;
    }
};