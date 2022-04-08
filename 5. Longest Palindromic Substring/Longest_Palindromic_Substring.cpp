class Solution {
public:
    int expandFromCenter(string&s, int L, int R){
        int l = 0;
        while(L >= 0 && R < s.size() && s[L] == s[R]){
            L--;
            R++;
        }
        return (R-L-1);
    }
    string longestPalindrome(string s) {
        int maxL = 0;
        int sL = s.size();
        int start = 0;
        
        for(int i = 0; i < sL; i++){
            int l1 = expandFromCenter(s,i,i);
            int l2 = expandFromCenter(s,i,i+1);
            int l = max(l1, l2);
            if(l > maxL){
                start = i - (l-1)/2;
                maxL = l;
            }
        }
        
        return s.substr(start, maxL);
    }
};