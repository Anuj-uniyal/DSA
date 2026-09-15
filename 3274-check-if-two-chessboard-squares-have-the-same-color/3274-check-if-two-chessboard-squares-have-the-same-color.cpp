class Solution {
public:
    bool checkTwoChessboards(string s1, string s2) {
        if(abs(s1[0]-s2[0])%2==0){
            if(abs(s1[1]-s2[1])%2==0){
           return true;
            }
            else
            {
                return false;
            }
        }
            
        
        else
        {
            if(abs(s1[1]-s2[1])%2==0){
           return false;
            }
            else{
                return true;
            }
        
        }
    }
};