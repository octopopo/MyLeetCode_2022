class Solution {
public:
    struct tNode{
        bool isWord = false;
        vector<tNode*> nextChar{vector<tNode*>(26, nullptr)};
    };
    
    class Trie{
        public:
        tNode* root;
        Trie(){
            root =  new tNode();
        }
        
        void insertWord(string& word){
            tNode* curr = root;
            int cInt;
            for(char& c : word){
                cInt = c - 'a';
                if(curr->nextChar[cInt] == nullptr){
                    curr->nextChar[cInt] = new tNode();
                }
                curr = curr->nextChar[cInt];
            }
            curr->isWord = true;
        }
        
        void getSuggestionsFromNode(string& prefix, tNode* node, vector<string>&res){
            if(res.size() == 3){
                return;
            }
            
            if(node->isWord){
                res.push_back(prefix);
            }
            
            for(int i = 0; i < 26; i++){
                if(node->nextChar[i] != nullptr){
                    prefix += (i+'a');
                    getSuggestionsFromNode(prefix, node->nextChar[i], res);
                    prefix.pop_back();
                }
            }
        }
        
        vector<string> getNextThreeWordWithPrefix(string& prefix){
            tNode* curr = root;
            int cInt;
            vector<string> res;
            for(char&c : prefix){
                cInt = c - 'a';
                if(curr->nextChar[cInt] == nullptr){
                    return res;
                }
                curr = curr->nextChar[cInt];
            }
            
            //Now we're at the prefix node
            
            getSuggestionsFromNode(prefix, curr, res);
            return res;
        }
    };
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> result;
        
        Trie tr;
        string temp = "";
        
        for(string s : products){
            tr.insertWord(s);
        }
        
        for(char& c : searchWord){
            temp += c;
            result.push_back(tr.getNextThreeWordWithPrefix(temp));
        }
        
        return result;
        
    }
};