class Solution {
public:
    int m;
    int n;
    vector<vector<char>> gPtr;
    bool isValidStep(int i, int j){
        if((i >= 0 && i < m) && (j >= 0 && j < n) && (gPtr[i][j] == 'O' || gPtr[i][j] == '#')){
            return true;
        }
        return false;
    };
    
    int getFood(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        queue<pair<int, int>> stepQ;
        gPtr = grid;
        //Find the character
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '*'){
                    stepQ.push({i, j});
                    gPtr[i][j] = 'X';
                }
            }
        }
        
        int qS;
        int stepCount = 0;
        //Start BFS
        while(!stepQ.empty()){
            qS = stepQ.size();
            for(int i = 0; i < qS; i++){
                int x = stepQ.front().first;
                int y = stepQ.front().second;
                stepQ.pop();
                
                if(grid[x][y] == '#'){
                    return stepCount;
                }
                
                if(isValidStep(x+1, y)){
                    stepQ.push({x+1, y});
                    gPtr[x+1][y] = 'X';
                }
                
                if(isValidStep(x-1, y)){
                    stepQ.push({x-1, y});
                    gPtr[x-1][y] = 'X';
                }
                
                if(isValidStep(x, y-1)){
                    stepQ.push({x, y-1});
                    gPtr[x][y-1] = 'X';
                }
                
                if(isValidStep(x, y+1)){
                    stepQ.push({x, y+1});
                    gPtr[x][y+1] = 'X';
                }
            }
            stepCount++;;
        }
        
        return -1;
    }
};