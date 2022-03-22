class Solution {
public:
    bool validPalindrome(string s) {
        int sL = s.size();
        return isPalindrome(s, 0, sL-1, false);
    }
    
    bool isPalindrome(string s, int head, int tail, bool hasDelete){
        while(head < tail){
            if(s[head] != s[tail]){
                if(!hasDelete){
                    return isPalindrome(s, head+1, tail, true) || isPalindrome(s, head, tail-1, true);
                }
                return false;
            }
            head++;
            tail--;
        }
        return true;
    }
};