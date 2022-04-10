class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int dim = matrix.size();
        
        for(int i = 0; i < (dim+1)/2; i++){
            for(int j = 0; j < dim/2; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[dim-1-j][i];
                matrix[dim-1-j][i] = matrix[dim-1-i][dim-1-j];
                matrix[dim-1-i][dim-1-j] = matrix[j][dim-1-i];
                matrix[j][dim-1-i] = temp;
            }
        }
    }
};