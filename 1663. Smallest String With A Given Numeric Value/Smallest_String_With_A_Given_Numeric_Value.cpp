class Solution {
public:
    string getSmallestString(int n, int k) {
        string res = "";
        string zpart = "";
        string apart = "";
        //This will be the number of Z
        int divZ = k/26;
        //This will be the remaining number
        int remZ = k%26;
        
        int remN = n-divZ;
        
        while(remZ < remN){
            remZ += 26;
            divZ--;
            remN = n-divZ;
        }
        
        for(int i = 0; i < divZ; i++){
            zpart += 'z';
        }
        
        n -= divZ;
        
        for(int i = 0; i < n-1; i++){
            apart += 'a';
        }
        
        if(n > 0){
            remZ -= (n);
            char lastC = remZ+'a';

            return apart + lastC + zpart;
        }
        
        return apart + zpart;
        
    }
};