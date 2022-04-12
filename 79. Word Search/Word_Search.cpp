class Solution {
public:
    bool isValidCell(vector<vector<char>>& board, int i, int j){
        //cout << i << " " << j << endl;
        if((i >= 0 && i < board.size()) && (j >= 0 && j < board[0].size()) && board[i][j] != '0'){
            return true;
        }
        
        return false;
    }
    bool dfsCheckWordExist(vector<vector<char>>& board, string& word, int nextWordToCheck, int startI, int startJ){
        bool checkResult;
        
        
        if(board[startI][startJ] != word[nextWordToCheck]){
            return false;
        }
        
        if(nextWordToCheck == word.size()-1){
            return true;
        }
        board[startI][startJ] = '0';
        
        int tempI = startI-1;
        int tempJ = startJ;
        
        if(isValidCell(board, tempI, tempJ)){
            if(dfsCheckWordExist(board, word, nextWordToCheck+1, tempI, tempJ)){
                return true;
            }
        }
        
        tempI = startI+1;
        
        if(isValidCell(board, tempI, tempJ)){
            if(dfsCheckWordExist(board, word, nextWordToCheck+1, tempI, tempJ)){
                return true;
            }
        }
        
        tempI = startI;
        tempJ = startJ+1;
        
        if(isValidCell(board, tempI, tempJ)){
            if(dfsCheckWordExist(board, word, nextWordToCheck+1, tempI, tempJ)){
                return true;
            }
        }
        
        tempJ = startJ-1;
        
        if(isValidCell(board, tempI, tempJ)){
            if(dfsCheckWordExist(board, word, nextWordToCheck+1, tempI, tempJ)){
                return true;
            }
        }
        board[startI][startJ] = word[nextWordToCheck]
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        
        for(int i =0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == word[0]){
                    if(dfsCheckWordExist(board, word, 0, i, j)){
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};