class Solution {
public:
    int passwordStrength(string password) {
        int count = 0;
        unordered_map<char,int> mp;

        for(int i = 0; i < password.size(); i++) {

            char ch = password[i];

            if(ch >= 'a' && ch <= 'z' && mp[ch] == 0) {
                mp[ch] = 1;
                count += 1;
            }
            else if(ch >= 'A' && ch <= 'Z' && mp[ch] == 0) {
                mp[ch] = 1;
                count += 2;
            }
            else if(ch >= '0' && ch <= '9' && mp[ch] == 0) {
                mp[ch] = 1;
                count += 3;
            }
            else if((ch == '!' || ch == '@' || ch == '#' || ch == '$')
                     && mp[ch] == 0) {
                mp[ch] = 1;
                count += 5;
            }
        }

        return count;
    }
};