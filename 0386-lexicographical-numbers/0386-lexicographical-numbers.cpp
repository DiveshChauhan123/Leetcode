class Solution {

    
public:
vector<int> ans;
    void solve(int i, int n){
        
        if(i>n){
            return;
        }

        int cur = i; 
        ans.push_back(cur);
        for(int i=0;i<=9;i++){
            string tmp = to_string(cur) + to_string(i); 
            solve(stoi(tmp),n);

            
        }
    }
    vector<int> lexicalOrder(int n) {

        for(int i=1;i<=9;i++){
            solve(i,n);
        }

        return ans;
    }
};