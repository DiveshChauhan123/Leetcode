class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int l;
        int b;
        double h;
        double d;
        int x,y;
        for(int i=0;i<dimensions.size();i++){
            l=dimensions[i][0];
            b=dimensions[i][1];
            d=sqrt(l*l+b*b);
            if(h<d){
                x=l;
                y=b;
                h=d;
            }
            else if(h==d){
                if(x*y<l*b){
                    x=l;
                    y=b;
                }
            }
        }
        return x*y;
    }
};