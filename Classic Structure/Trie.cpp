class Solution {
    struct WordNode{
        bool isWord = false;
        vector<WordNode*> nextChar {vector<WordNode*>(26, NULL)};
    };
    
    class Trie{
        private:
        public:
        WordNode* root;
        WordNode* curr;
        
        Trie(){
            root = new WordNode();
        }
        
        void insertNode(string& product){
            int cIndex;
            curr = root;
            for(char& c : product){
                cIndex = c - 'a';
                if(curr->nextChar[cIndex] == NULL){
                    curr->nextChar[cIndex] = new WordNode();
                }
                curr = curr->nextChar[cIndex];
            }
            
            curr->isWord = true;
        }
        
        void getSuggestionsWithPrefix(string &prefix, vector<string>& result, WordNode* node){
            if(result.size() == 3){
                return;
            }
            
            if(node->isWord){
                result.push_back(prefix);
            }
            
            for(int i = 0; i < node->nextChar.size(); i++){
                if(node->nextChar[i] == NULL){
                    continue;
                }
                
                prefix += (i + 'a');
                getSuggestionsWithPrefix(prefix, result, node->nextChar[i]);
                prefix.pop_back();
            }
            
        }
        
        vector<string> getSuggestionFromRoot(string& prefix){
            curr = root;
            int cIndex;
            vector<string> res;
            for(char& c : prefix){
                cIndex = c - 'a';
                //can't find the word
                if(curr->nextChar[cIndex] == NULL){
                    return res;
                }
                curr = curr->nextChar[cIndex];
            }
            
            getSuggestionsWithPrefix(prefix, res, curr);
            return res;
        }
        
        vector<vector<string>> getAllSuggestionsForWord(string& word){
            string target = "";
            vector<vector<string>> res;
            for(char& c : word){
                target += c;
                res.push_back(getSuggestionFromRoot(target));
            }
            
            return res;
        }
    };
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie;
        
        for(string p : products){
            trie.insertNode(p);
        }
        
        return trie.getAllSuggestionsForWord(searchWord);
    }
};