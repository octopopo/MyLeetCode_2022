class Solution {
public:
    void reverseString(string& s, int start, int end){
        //cout << start << " " << end << endl;
        int l = end-start+1;
        for(int i = 0; i < (l/2); i++){
            char c = s[start + i];
            //cout << c << endl;
            s[start + i] = s[end-i];
            //cout << "end-i: "<< s[end-i] << endl;
            s[end-i] = c;
        }
    }
    string reverseWords(string s) {
        int start = -1;
        int sL = s.size();
        for(int i = 0; i < sL; i++){
            if(start == -1){
                if(s[i] != ' '){
                    start = i;
                }
            }
            else{
                if(s[i] == ' '){
                    reverseString(s, start, i-1);
                    start = -1;
                }
            }
        }
        
        if(start != -1){
            reverseString(s, start, sL-1);
        }
        
        return s;
    }
};