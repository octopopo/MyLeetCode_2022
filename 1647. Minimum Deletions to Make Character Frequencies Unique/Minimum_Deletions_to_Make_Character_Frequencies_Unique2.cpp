class Solution {
public:
    int minDeletions(string s) {
        vector<int> charToFreq(26, 0);
        priority_queue<int> pq;
        int tempPtr;
        int prev, curr;
        int totalCount = 0;
        
        for(char& c : s){
            charToFreq[c-'a']++;
        }
        
        for(int i = 0; i < 26; i++){
            tempPtr = charToFreq[i];
            if(tempPtr == 0){
                continue;
            }
            pq.push(tempPtr);
        }
        
        while(pq.size() > 1){
            prev = pq.top();
            pq.pop();
            curr = pq.top();
            
            //cout << "p: " << prev << " c: " << curr << endl;
            
            if(prev==curr){
                prev--;
                totalCount++;
                
                if(prev > 0){
                    pq.push(prev);
                }
            }
        }
        
        return totalCount;
    }
};