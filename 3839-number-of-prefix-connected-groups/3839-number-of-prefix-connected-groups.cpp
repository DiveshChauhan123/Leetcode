class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        for(int i=0;i<words.size();i++){
            if(words[i].size()>=k){
                words[i]=words[i].substr(0,k);
            }
        }
        sort(words.begin(),words.end());
        unordered_map<string,int>mp;
        int count=0;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
            if(words[i].size()==k && mp[words[i]]==2)count++;
        }
        return count;
    }
};