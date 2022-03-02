class Solution {
public:
    bool isSubsequence(string s, string t) {
        //either size or length would work
        int tLength = t.size();
        int sLength = s.size();
        
        if(tLength == 0){
            if(sLength == 0){
                return true;
            }
            return false;
        }
        
        
        int sHead = 0;
        int tHead = 0;
        
        for(int i = 0; i < t.size(); i++){
            if(sHead >= sLength){
                return true;
            }
            if(t[i] == s[sHead]){
                sHead++;
            }
        }
        
        if(sHead >= sLength){
            return true;
        }
        
        return false;
    }
};