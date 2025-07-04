class Solution {
public:
    int maxVowels(string s, int k) {
        int i=0;
        int j=0;
        int count=0;
        int maxval=INT_MIN;
        while(j<s.size()){
            if(s[j]=='a' || s[j]=='e' || s[j]=='i' ||s[j]=='o'|| s[j]=='u'){
                count++;
            }
            if(j-i+1==k){
                maxval=max(maxval,count);
                if(s[i]=='a' || s[i]=='e' || s[i]=='i' ||s[i]=='o'|| s[i]=='u')count--;
                i++;
            }
            j++;
        }
        return maxval;
    }
};