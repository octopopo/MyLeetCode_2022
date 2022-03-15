class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> appearance(26, 0);
        unordered_map<char, queue<int>*> charToPositions;
        int oL = s1.size();
        int tL = s2.size();
        char temp;
        
        for(int i = 0; i < oL; i++){
            temp = s1[i];
            appearance[temp - 'a']++;
            charToPositions[temp] = new queue<int>();
        }
        
        //for(int i = 0; i < 26; i++){
          //  cout << i+'a' << " count: " << appearance[i] << endl;
        //}
        
        for(int i = 0; i < tL; i++){
            temp = s2[i];
            if(!charToPositions.count(temp)){
                //cout << "call clearMap pos" << i << "char is: " << temp << endl;
                clearMap(charToPositions);
                //cout << "the size of b: " << charToPositions['b']->size() << endl;
            }
            else{
                //cout << "Found something in the map: "<< s2[i] << endl;
                charToPositions[temp]->push(i);
                
                if(charToPositions[temp]->size() == appearance[temp-'a']){
                    bool result = checkIfPermutation(charToPositions, appearance);
                    if(result){
                        return true;
                    }
                }
                
                if(charToPositions[temp]->size() > appearance[temp-'a']){
                    removePosBelowTarget(charToPositions, temp);
                }
                
            }
        }
        
        return false;
    }
    
    void clearMap(unordered_map<char, queue<int>*>&map){
        for(pair<char, queue<int>*> kvp : map){
            while(!kvp.second->empty()){
                kvp.second->pop();
            }
        }
    }
    
    bool checkIfPermutation(unordered_map<char, queue<int>*>map, vector<int>& appearance){
        for(pair<char, queue<int>*> kvp : map){
            if(kvp.second->size() != appearance[kvp.first - 'a']){
                return false;
            }
        }
        return true;
    }
    
    void removePosBelowTarget(unordered_map<char, queue<int>*> &map, char target){
        int smallesValidPos = map[target]->front();
        map[target]->pop();
        
        for(pair<char, queue<int>*> kvp : map){
            while(!kvp.second->empty()){
                if(kvp.second->front() < smallesValidPos){
                    kvp.second->pop();
                }
                else{
                    break;
                }
            }
        }
    }
        
};