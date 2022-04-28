class Solution {
public:
    void reverseString(vector<char>& s) {
        int sL = s.size();
        
        for(int i = 0; i < sL/2; i++){
            char c = s[i];
            s[i] = s[sL-1-i];
            s[sL-1-i] = c;
        }
        
    }
};