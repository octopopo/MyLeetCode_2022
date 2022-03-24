class Solution {
public:
    string res = "";
    stack<char> decodeStack;
    int sL = 0;
    string decodeString(string s) {
        sL = s.size();
        char temp;
        for(int i = 0; i < sL; i++){
            temp = s[i];
            if(decodeStack.empty()){
                if((temp >= '0' && temp <= '9')){
                    decodeStack.push(temp);
                    continue;
                }
                res += temp;
            }
            else{
                if(temp == ']'){
                    decodeOneSet();
                }
                else{
                    decodeStack.push(temp);
                }
            }
        }
        
        return res;
    }
    
    void decodeOneSet(){
        char top = decodeStack.top();
        string repS = "";
        while(top != '['){
            repS = top + repS;
            decodeStack.pop();
            top = decodeStack.top();
        }
        decodeStack.pop(); // pop [
        
        top = decodeStack.top();
        int num = 0;
        int powT = 0;
        while(top <= '9' && top >= '0'){
            num = (top - '0') * pow(10, powT) + num;
            decodeStack.pop();
            if(decodeStack.empty()){
                break;
            }
            top = decodeStack.top();
            powT++;
        }
        
        string temp = "";
        
        for(int i = 0; i < num; i++){
            temp += repS;
        }
        
        if(decodeStack.empty()){
            res = res + temp;
        }
        else{
            for(int i = 0; i < temp.size(); i++){
                decodeStack.push(temp[i]);
            }
        }
    }
    
    
    
};