class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int p=0,m=0,g=0;
        int x=0,y=0,z=0;
        for(int i=0;i<garbage.size();i++){
            string s=garbage[i];
            bool a=false,b=false,c=false;
            for(char ch:s){
                if(ch=='P'){
                    p++;
                    a=true;
                }
                else if(ch=='M'){
                    m++;
                    b=true;
                }
                else{
                    g++;
                    c=true;
                }
            }
            if(a){
                p+=x;
                x=0;
            }
            if(b){
                m+=y;
                y=0;
            }
            if(c){
                g+=z;
                z=0;
            }
            if(i<garbage.size()-1){
                x+=travel[i];
                y+=travel[i];
                z+=travel[i];
            }
        }
        return p+m+g;
    }
};