class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rowL = mat.size();
        int colL = mat[0].size();
        //Minus 20000 is because that's the potential of max row + col
        vector<vector<int>> result(rowL, vector<int>(colL, INT_MAX-20000));
        
        
        for(int i = 0 ; i < rowL; i++){
            for(int j = 0; j < colL; j++){
                if(mat[i][j] == 0){
                    result[i][j] = 0;
                    continue;
                }
                
                if(i == 0 && j == 0){
                    continue;
                }
                
                if(i == 0){
                    result[i][j] = result[i][j-1] + 1;
                    continue;
                }
                
                if(j == 0){
                    result[i][j] = result[i-1][j] + 1;
                    continue;
                }
                
                
                result[i][j] = min(result[i][j-1], result[i-1][j]) + 1;
            }
        }
        
        for(int i = rowL-1; i>= 0; i--){
            for(int j = colL-1; j>=0; j--){
                if(mat[i][j] == 0){
                    continue;
                }
                
                if(i+1 >= rowL && j+1 >= colL){
                    continue;
                }
                
                if(i+1 >= rowL){
                    result[i][j] = min(result[i][j+1] + 1, result[i][j]);
                    continue;
                }
                
                if(j+1 >= colL){
                    result[i][j] = min(result[i+1][j] + 1, result[i][j]);
                    continue;
                }
                
                result[i][j] = min(result[i][j], result[i][j+1]+1);
                result[i][j] = min(result[i][j], result[i+1][j]+1);
            }
        }
        
        return result;
    }
};