class Solution {
public:
    int dimension;
    int totalBlock;
    int getRow(int num){
        return dimension-1 - ((num-1)/dimension);
    }
    
    int getCol(int num){
        int remain = (num-1) % dimension;
        int row = getRow(num);
        return (dimension - row)%2 == 1 ? remain : (dimension-1) - remain;
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        dimension = board.size();
        totalBlock = dimension*dimension;
        vector<int> vis(dimension*dimension+1);
        queue<int> stepQ;
        int qSize = 0;
        stepQ.push(1);
        int qNum;
        int nNum;
        int steps = 0;
        
        int oldR, oldC;
        int newR, newC;
        
        while(!stepQ.empty()){
            qSize = stepQ.size();
            
            for(int i = 0 ; i < qSize; i++){
                qNum = stepQ.front();
                //cout << qNum << endl;
                stepQ.pop();
                
                if(vis[qNum] == 1){
                    continue;
                }
                
                if(qNum == totalBlock){
                    return steps;
                }
                
                vis[qNum] = 1;
                
                
                for(int j = 1; j <= 6; j++){
                    nNum = qNum + j;
                    if(nNum > totalBlock){
                        break;
                    }
                    newR = getRow(nNum);
                    newC = getCol(nNum);
                    
                    
                    if(board[newR][newC] == -1){
                        stepQ.push(nNum);
                    }
                    else{
                        
                        stepQ.push(board[newR][newC]);
                    }
                }
            }
            steps++;
                
        }
        
        return -1;
    }
};