#include<stdlib.h>
class Solution {
public:
    unordered_map<string, int> domainToCount;
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        int cL = cpdomains.size();
        vector<string> res;
        for(int i = 0; i < cL; i++){
            parseOneString(cpdomains[i]);
        }
        
        for(unordered_map<string, int>::iterator it = domainToCount.begin(); it != domainToCount.end(); it++){
            string temp = to_string(it->second) + " " + it->first;
            res.push_back(temp);
        }
        
        return res;
    }
    
    void parseOneString(string& singleLine){
        char * token;
        token = strtok(&singleLine[0], " ");
        int number = atoi(token);
        vector<string> splitResult;
        string combine = "";
        while(token != NULL){
            token = strtok(NULL, ".");
            if(token != NULL){
                splitResult.push_back(token);
            }
        }
        
        int sL = splitResult.size();
        
        for(int i = sL-1; i >= 0; i--){
            combine = splitResult[i] + combine;
            domainToCount[combine] += number;
            combine = "." + combine;

        }
    }
};