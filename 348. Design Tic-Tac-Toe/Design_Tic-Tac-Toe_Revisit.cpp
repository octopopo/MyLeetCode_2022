class TicTacToe {
public:
    
    vector<vector<int>> rowR;
    vector<vector<int>> colR;
    vector<vector<int>> diagR;
    int dim;
    
    TicTacToe(int n) {
        rowR = vector<vector<int>>(n, vector<int>(2, 0));
        colR = vector<vector<int>>(n, vector<int>(2, 0));
        diagR = vector<vector<int>>(2, vector<int>(2, 0));
        dim = n;
    }
    
    int move(int row, int col, int player) {
        int result = addCountR(row, player);
        if(result != 0){
            return result;
        }
        result = addCountC(col, player);
        if(result != 0){
            return result;
        }
        
        if(row == col){
            result = addDiag(0, player);
        }
        if(row + col == dim-1){
            result = addDiag(1, player);
        }
        
        return result;
    }
    
    int addCountR(int row, int player){
        rowR[row][player-1]++;
        if(rowR[row][player-1] == dim){
            return player;
        }
        return 0;
    }
    
    int addCountC(int col, int player){
        colR[col][player-1]++;
        if(colR[col][player-1] == dim){
            return player;
        }
        return 0;
    }
    
    int addDiag(int diag, int player){
        diagR[diag][player-1]++;
        if(diagR[diag][player-1] == dim){
            return player;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */