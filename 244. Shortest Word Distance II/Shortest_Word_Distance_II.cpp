class WordDistance {
public:
    unordered_map<string, vector<int>> dic;
    WordDistance(vector<string>& wordsDict) {
        int wL = wordsDict.size();
        for(int i = 0; i < wL; i++){
            dic[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int ptr1 = 0;
        int ptr2 = 0;
        int minDif = INT_MAX;
        int num1, num2;
        
        while(ptr1 < dic[word1].size() && ptr2 < dic[word2].size()){
            num1 = dic[word1][ptr1];
            num2 = dic[word2][ptr2];
            
            minDif = min(minDif, abs(num1 - num2));
            
            if(num2 > num1){
                ptr1++;
            }
            else{
                ptr2++;
            }
        }
        
        return minDif;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */