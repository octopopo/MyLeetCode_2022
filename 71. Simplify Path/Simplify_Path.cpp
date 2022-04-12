class Solution {
public:
    string simplifyPath(string path) {
        string temp = "";
        string res = "";
        stack<string> pathStack;
        int pathLength = path.size();
        
        for(int i = 0; i < pathLength; i++){
            if(i >= 1 && path[i] == '/' && path[i-1] != '/'){
                //cout << temp << endl;
                if(temp == "." || temp == ""){
                    temp = "";
                    continue;
                }
                if(temp == ".."){
                    if(!pathStack.empty()){
                        //cout << "pop" << endl;
                        pathStack.pop();
                    }
                }
                else{
                    //cout << "push" << endl;
                    pathStack.push(temp);
                }
                temp = "";
            }
            else if(path[i] != '/'){
                temp += path[i];
            }
        }
        
        if(temp != ".." && temp != "." && temp != ""){
            pathStack.push(temp);
        }
        else if(temp == ".."){
            if(!pathStack.empty()){
                pathStack.pop();
            }
        }
        
        while(!pathStack.empty()){
            if(pathStack.top() != ""){
                res = "/" + pathStack.top() + res;
            }
            pathStack.pop();
        }
        
        return res.size() > 0 ? res : "/";
    }
};