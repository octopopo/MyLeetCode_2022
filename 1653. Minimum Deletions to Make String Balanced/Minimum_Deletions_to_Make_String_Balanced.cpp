class Solution {
public:
    int minimumDeletions(string s) {
        int countA = 0;
        int countB = 0;
        int sL = s.size();
        int res = sL;
        int aOnLeft = 0;
        int aOnRight;
        int bOnLeft = 0;
        if(sL < 2){
            return 0;
        }
        
        for(int i = 0; i < sL; i++){
            if(s[i] == 'a'){
                countA++;
            }
            else{
                countB++;
            }
        }
        
        if(countA == 0 || countB == 0){
            return 0;
        }
        
        
        for(int i = 0; i < sL; i++){
            aOnRight = countA-aOnLeft-(s[i] == 'a' ? 1 : 0);
            res = min(res, aOnRight + bOnLeft);
            
            if(s[i] == 'a'){
                aOnLeft++;
            }
            else{
                bOnLeft++;
            }
        }
        
        return res;
    }
};