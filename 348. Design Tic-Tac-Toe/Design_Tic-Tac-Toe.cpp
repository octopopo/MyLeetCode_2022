class TicTacToe {
public:
    vector<int> rowRecord;
    vector<int> colRecord;
    vector<int> diagRecord;
    vector<int> rowCount;
    vector<int> colCount;
    vector<int> diagCount;
    int dimension;
    TicTacToe(int n) {
        rowRecord = vector<int>(n, 0);
        colRecord = vector<int>(n, 0);
        diagRecord = vector<int>(2, 0);
        rowCount = vector<int>(n, 0);
        colCount = vector<int>(n, 0);
        diagCount = vector<int>(2, 0);
        dimension = n;
    }
    
    int move(int row, int col, int player) {
        if(rowRecord[row] == 0){
            rowRecord[row] = player;
        }
        if(rowRecord[row] > 0 && rowRecord[row] != player){
            rowRecord[row] = -1;
        }
        rowCount[row]++;
        if(rowCount[row] == dimension && rowRecord[row] > 0){
            return rowRecord[row];
        }
        
        if(colRecord[col] == 0){
            colRecord[col] = player;
        }
        if(colRecord[col] > 0 && colRecord[col] != player){
            colRecord[col] = -1;
        }
        colCount[col]++;
        
        //cout << "col: " << col << " count: " << colCount[col] << endl;
        
        if(colCount[col] == dimension && colRecord[col] > 0){
            return colRecord[col];
        }
        
        if(row == col){
            if(diagRecord[0] > 0 && diagRecord[0] != player){
                diagRecord[0] = -1;
            }
            
            if(diagRecord[0] == 0){
                diagRecord[0] = player;
            }
            
            diagCount[0]++;
            
            if(diagCount[0] == dimension && diagRecord[0] > 0){
                return diagRecord[0];
            }
        }
        if(row+col == dimension-1){
            if(diagRecord[1] > 0 && diagRecord[1] != player){
                diagRecord[1] = -1;
            }
            
            if(diagRecord[1] == 0){
                diagRecord[1] = player;
            }
            
            diagCount[1]++;
            
            if(diagCount[1] == dimension && diagRecord[1] > 0){
                return diagRecord[1];
            }
        }
        
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */