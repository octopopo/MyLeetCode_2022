class Solution {
public:
    string decodeString(string s) {
        string res = "";
        string temp = "";
        stack<int> numStack;
        stack<string> stringStack;
        int curNum = 0;
        
        for(int i = 0; i < s.size(); i++){
            //cout <<"si " << s[i] << endl; 
            if(isdigit(s[i])){
                curNum = curNum* 10 + s[i]-'0';
            }
            else if(isalpha(s[i])){
                //cout << "tt " << temp << endl;
                temp += s[i];
            }
            else if(s[i] == ']'){
                int tN = numStack.top();
                string last = stringStack.top();
                for(int j = 0; j < tN; j++){
                    last += temp;
                }
                
                numStack.pop();
                stringStack.pop();
                //cout << temp << endl;
                temp = last;
            }
            else{
                //cout << "t: " << temp << endl;
                //cout << curNum << endl;
                stringStack.push(temp);
                numStack.push(curNum);
                temp = "";
                curNum = 0;
            }
        }
        return temp;
    }
};