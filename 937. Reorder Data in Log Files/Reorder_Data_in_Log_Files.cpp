class Solution {
public:
    static bool compare(string a, string b){
        int notIinA, notIinB;
        //cout << "a: " << a << " b: " << b << endl;
        for(int i = 0; i < a.size(); i++){
            if(a[i] == ' '){
                notIinA = i+1;
                break;
            }
        }
        
        for(int i = 0; i < b.size(); i++){
            if(b[i] == ' '){
                notIinB = i+1;
                break;
            }
        }
        
        int i = 0;
        
        while(notIinA + i < a.size() && notIinB + i < b.size()){
            //cout << "notIinA+i: " << to_string(notIinA+i) << " is: " << a[notIinA+i] << endl;
            //cout << "notIinB+i: " << to_string(notIinB+i) << " is: " << b[notIinB+i] << endl;
            if(a[notIinA+i] < b[notIinB + i]){
                return true;
            }
            else if(a[notIinA+i] > b[notIinB + i]){
                return false;
            }
            i++;
        }
        
        if((int)a.size() - notIinA != (int)b.size()-notIinB){
            return (int)a.size()-notIinA < (int)b.size()-notIinB;
        }
        //cout << "here" << endl;
        for(int i = 0; i <= a.size() && i <= b.size(); i++){
            if(a[i] < b[i]){
                return true;
            }
            else{
                return false;
            }
        }
        return true;
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        int digitPointer = logs.size()-1;
        for(int i = logs.size()-1; i >= 0; i--){
            if(isDigitLog(logs[i])){
                //cout << logs[i] << endl;
                string buffer = logs[digitPointer];
                logs[digitPointer] = logs[i];
                logs[i] = buffer;
                digitPointer--;
            }
        }
        sort(logs.begin(), logs.begin() + digitPointer+1, compare);
        return logs;
    }
    
    bool isDigitLog(string log){
        for(int i = log.size()-1; i>= 0; i--){
            if(log[i] >= '0' && log[i] <= '9'){
                //cout << log[i] << endl;
                return true;
            }
            else{
                return false;
            }
        }
        return false;
    }
};