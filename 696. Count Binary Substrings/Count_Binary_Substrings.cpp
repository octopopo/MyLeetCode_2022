class Solution {
public:
    int countBinarySubstrings(string s) {
        int oCount = 0;
        int zCount = 0;
        int sum = 0;
        char lastC;
        
        for(char&c : s){
            if(oCount != 0 && zCount != 0){
                if(lastC == c){
                    if(c == '0'){
                        oCount++;
                    }
                    else if(c == '1'){
                        zCount++;
                    }
                }
                else{
                    sum += min(oCount, zCount);
                    if(c == '0'){
                        oCount = 1;
                    }
                    else{
                        zCount = 1;
                    }
                }
            }
            else{
                if(c == '0'){
                    oCount++;
                }
                else if(c == '1'){
                    zCount++;
                }
            }
            
            lastC = c;
        }
        
        sum += min(oCount, zCount);
        
        return sum;
    }
};