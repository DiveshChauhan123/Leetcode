class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>>result;
        for(int i=0;i<words.size();i++){
            string top=words[i];
            for(int j=0;j<words.size();j++){
                string left=words[j];
                if(i==j || top[0]!=left[0])continue;
                else{
                    for(int k=0;k<words.size();k++){
                    string right=words[k];
                    if(k==i || k==j || top[3]!=right[0]){
                        continue;
                    }
                    else{
                        for(int l=0;l<words.size();l++){
                            string bottom=words[l];
                            if(i==l || j==l || k==l || bottom[0]!=left[3] || bottom[3]!=right[3]){
                                continue;
                            }
                            else{
                                result.push_back({top,left,right,bottom});
                            }
                        }
                    }
                    
                }
                }
            }
        }
        sort(result.begin(),result.end());
        return result;
    }
};