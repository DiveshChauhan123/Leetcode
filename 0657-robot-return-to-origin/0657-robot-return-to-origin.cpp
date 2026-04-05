class Solution {
public:
    bool judgeCircle(string moves) {
        int n=moves.size();
        int x=0,y=0;
        for(int i=0;i<n;i++){
            if(moves[i]=='U')x--;
            else if(moves[i]=='D')x++;
            else if(moves[i]=='L')y--;
            else{
                y++;
            }
        }
        if(x==0 && y==0)return true;
        return false;
    }
};