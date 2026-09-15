class Solution {
public:
    bool squareIsWhite(string s) {
        if((s[0]-'a')%2==0){
            if(s[1]%2==0){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            if(s[1]%2==0){
                return false;
            }
            else{
                return true;
            }
        }
    }
};