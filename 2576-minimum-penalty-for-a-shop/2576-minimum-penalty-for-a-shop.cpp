class Solution {
public:
    int bestClosingTime(string customers) {
        int y=0,n=0;
        for(int i=0;i<customers.size();i++){
            if(customers[i]=='Y')y++;
        }
        int x=0;
        int p=y;
        for(int i=0;i<customers.size();i++){
            if(customers[i]=='Y')y--;
            else if(customers[i]=='N')n++;
            int z=y+n;
            if(p>z){
                x=i+1;
                p=z;
            }
        }
        return x;
    }
};