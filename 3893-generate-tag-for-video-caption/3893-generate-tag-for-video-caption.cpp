class Solution {
public:
    string generateTag(string caption) {
        string p = "#";
        if(caption[0]!=' '){
            p+=tolower(caption[0]);
        }
        bool capitalize = false;

        for(int i=1;i<caption.size();i++){
            if(p.size()==100)break;
            if(caption[i]==' '){
                capitalize=true;
                continue;
            }
            else{
                if(capitalize){
                    p+=toupper(caption[i]);
                    capitalize=false;
                }
                else{
                    p+=tolower(caption[i]);
                }
            }
        }
        return p;
    }
};
