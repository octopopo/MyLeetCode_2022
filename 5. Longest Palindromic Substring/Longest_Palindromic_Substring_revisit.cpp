class Solution {
public:
    int expandTwoSideFromThisPoint(string& s, int L, int R){
        while(L >= 0 && R <= s.size() && s[L] == s[R]){
            L--;
            R++;
        }
        
        return (R-L-1);
    }
    string longestPalindrome(string s) {
        int sL = s.size();
        int maxL = 0;
        int startPos;
        
        for(int i = 0; i < sL; i++){
            int sR = expandTwoSideFromThisPoint(s, i, i);
            int dR = expandTwoSideFromThisPoint(s, i, i+1);
            

            
            if(sR > dR){
                if(sR > maxL){
                    maxL = sR;
                    startPos = i - (sR-1)/2;
                }
            }
            else{
                if(dR > maxL){
                    maxL = dR;
                    startPos = i-(dR-1)/2;
                }
            }
        }
        
        return s.substr(startPos, maxL);
        
    }
};