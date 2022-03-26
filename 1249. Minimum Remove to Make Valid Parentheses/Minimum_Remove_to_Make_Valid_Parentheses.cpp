class Solution {
public:
    stack<int> leftS;
    stack<int> rightS;
    string minRemoveToMakeValid(string s) {
        string res;
        int sL = s.size();
        int temp;
        
        for(int i = 0; i < sL; i++){
            if(s[i] == '('){
                leftS.push(i);
            }
            else if(s[i] == ')'){
                if(!leftS.empty()){
                    leftS.pop();
                }
                else{
                    rightS.push(i);
                }
            }
        }
        
        while(!leftS.empty()){
            temp = leftS.top();
            leftS.pop();
            s[temp] = '0';
        }
        
        while(!rightS.empty()){
            temp = rightS.top();
            rightS.pop();
            s[temp] = '0';
        }
        
        for(int i = 0; i < sL; i++){
            if(s[i] != '0'){
                res += s[i];
            }
        }
        
        return res;
    }
};