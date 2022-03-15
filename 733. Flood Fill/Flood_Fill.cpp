class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int originalColor = image[sr][sc];
        if(originalColor == newColor){
            return image;
        }
        image[sr][sc] = newColor;
        
        int tempR, tempC;
        
        tempR = sr-1;
        if(tempR >= 0){
            if(image[tempR][sc] == originalColor){
                floodFill(image, tempR, sc, newColor);
            }
        }
        
        tempR = sr+1;
        if(tempR < image.size()){
            if(image[tempR][sc] == originalColor){
                floodFill(image, tempR, sc, newColor);
            }
        }
        
        tempC = sc-1;
        if(tempC >= 0){
            if(image[sr][tempC] == originalColor){
                floodFill(image, sr, tempC, newColor);
            }
        }
        
        tempC = sc+1;
        if(tempC < image[0].size()){
            if(image[sr][tempC] == originalColor){
                floodFill(image, sr, tempC, newColor);
            }
        }
        
        return image;
    }
};