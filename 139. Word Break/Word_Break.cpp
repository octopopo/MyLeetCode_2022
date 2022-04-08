class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int sL = s.size();
        unordered_map<int , set<string>> lengthToWordSet;
        vector<bool> dpRecord(sL , false);
        int maxWL, minWL;
        int wL = wordDict.size();
        string tempS = wordDict[0];
        int tL = tempS.size();
        maxWL = tL;
        minWL = tL;
        lengthToWordSet[tL].insert(tempS);
        
        
        for(int i = 1; i < wL; i++){
            tempS = wordDict[i];
            tL = tempS.size();
            lengthToWordSet[tL].insert(tempS);
            maxWL = max(maxWL, tL);
            minWL = min(minWL, tL);
        }
        
        string sub1, sub2;
        //cout << "minWL " << minWL << endl;
        for(int i = 0; i < sL; i++){
            if(i < minWL-1){
                dpRecord[i] = false;
                continue;
            }
            
            sub1 = s.substr(0, i+1);
            
            //cout << sub1 << endl;
            //cout << "_______" << endl;
            
            if(lengthToWordSet.count(sub1.size())){
                if(lengthToWordSet[sub1.size()].count(sub1)){
                    dpRecord[i] = true;
                    continue;
                }
            }
            
            for(int j = i; j >= 1; j--){
                sub2 = sub1.substr(j, i-j+1);
                //cout << sub2 << endl;
                if(lengthToWordSet.count(sub2.size())){
                    if(lengthToWordSet[sub2.size()].count(sub2)){
                        //cout << "here " << j << endl;
                        dpRecord[i] = dpRecord[j-1];
                        if(dpRecord[i]){
                            break;
                        }
                        continue;
                    }
                }
            }
            
        }
        
        return dpRecord.back();
    }
};