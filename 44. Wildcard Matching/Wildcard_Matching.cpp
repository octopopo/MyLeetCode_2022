class Solution {
public:
    bool isMatch(string s, string p) {
        int sL = s.size();
        int pL = p.size();
        
        if(pL > 0){
            int i;
            for(i = 0; i < pL; i++){
                if(p[i] != '*'){
                    break;
                }
            }
            
            //All char in p is *
            if(i == pL){
                return true;
            }
        }
        
        if(pL == 0 && sL == 0){
            return true;
        }
        
        //if P is not all * and one of them is empty
        //Then it surely won't match
        if(pL == 0 || sL == 0){
            return false;
        }
        //row means -1-i of p, col -1-i of s
        vector<vector<bool>> record(pL+1, vector<bool>(sL+1, false));
        
        record[0][0] = true;
        
        for(int i = 1; i < pL+1; i++){
            if(p[i-1] == '*'){
                int sI = 1;
                
                while((!record[i-1][sI-1]) && sI < sL+1){
                    sI++;
                }
                
                record[i][sI-1] = record[i-1][sI-1];
                
                while(sI < sL+1){
                    record[i][sI] = true;
                    sI++;
                }
            }
            else if(p[i-1] == '?'){
                for(int sI = 1; sI < sL + 1; sI++){
                    record[i][sI] = record[i-1][sI-1];
                }
            }
            else{
                for(int sI = 1; sI < sL + 1; sI++){
                    record[i][sI] = record[i-1][sI-1] && (p[i-1] == s[sI-1]);
                }
            }
        }
        
        return record[pL][sL];
    }
};