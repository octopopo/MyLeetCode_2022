class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> charToFreq;
        unordered_map<int, vector<char>>freqToChars;
        int sL = s.size();
        int totalMove = 0;
        
        for(char& c : s){
            charToFreq[c]++;
        }
        
        for(unordered_map<char,int>::iterator it = charToFreq.begin(); it != charToFreq.end(); it++){
            freqToChars[it->second].push_back(it->first);
        }
        
        for(unordered_map<int, vector<char>>::iterator it = freqToChars.begin(); it!= freqToChars.end(); it++){
            int freq = it->first;
            int charCount = it->second.size();
            if(charCount >= 2){
                for(int i = charCount-1; i >= 1; i--){
                    int temp = freq;
                    char c = it->second[i];
                    while(temp >= 0 && freqToChars.count(temp)){
                        temp--;
                        totalMove++;
                    }
                    
                    it->second.pop_back();
                    
                    if(temp != 0){
                        freqToChars[temp].push_back(c);
                    }
                    
                }
            }
        }
        
        return totalMove;
    }
};