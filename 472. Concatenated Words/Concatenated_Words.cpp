class Solution {
public:
    struct LetterNode{
        bool isWord = false;
        vector<LetterNode*> nextChar{vector<LetterNode*>(26, NULL)};
    };
    class Trie{
        public:
        LetterNode* root;
        LetterNode* current;
        int longestWordSize;
        
        Trie(){
            root = new LetterNode();
            longestWordSize = 0;
        }
        
        void insertWord(string word){
            if(word.size() == 0){
                    return;
                }
            current = root;
            int currentChar;
            int wordCount = word.size();
            longestWordSize = max(longestWordSize, wordCount);
            for(int i = 0; i < wordCount; i++){
                currentChar = word[i]-'a';
                if(current->nextChar[currentChar] == NULL){
                    current->nextChar[currentChar] = new LetterNode();
                }
                current = current->nextChar[currentChar];
            }
            current->isWord = true;
        }
        
        bool IsConcatenatedWord(string word){
            int totalWord = 0;
            current = root;
            for(int i = 0; i < word.size(); i++){
                if(current->isWord){
                    if(isWord(word.substr(i))){
                        return true;
                    }
                }
                current = current->nextChar[word[i]-'a'];
            }
            
            return false;
        }
        
        bool isWord(string word){
            LetterNode* temp = root;
            for(int i = 0; i < word.size(); i++){
                if(temp->isWord){
                    if(isWord(word.substr(i))){
                        return true;   
                    }
                }
                
                if(temp->nextChar[word[i]-'a'] == NULL){
                    return false;
                }
                
                temp = temp->nextChar[word[i]-'a'];
            }
            return temp->isWord;
        }
        
        vector<string> findAllConcatenated(vector<string>& words){
            vector<string> res;
            for(int i = words.size()-1; i >= 0; i--)
            {
                if(IsConcatenatedWord(words[i])){
                    res.push_back(words[i]);
                }
            }
            return res;
        }
        
    };
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie trie;
        int wL = words.size();
        vector<string> res;
        
        for(int i = 0; i < wL; i++){
            trie.insertWord(words[i]);
        }
        
        
        return trie.findAllConcatenated(words);
    }
};