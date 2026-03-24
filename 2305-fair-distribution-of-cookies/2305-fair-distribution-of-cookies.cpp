class Solution {
public:
int result=INT_MAX;
void solve(int idx,vector<int>&cookies,int k,vector<int>&child){
    if(idx>=cookies.size()){
        int uni=*max_element(child.begin(),child.end());
        result=min(uni,result);
        return;
    }
    for(int i=0;i<k;i++){
        child[i]+=cookies[idx];
        solve(idx+1,cookies,k,child);
        child[i]-=cookies[idx];
    }
}
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>child(k,0);
        solve(0,cookies,k,child);
        return result;
    }
};