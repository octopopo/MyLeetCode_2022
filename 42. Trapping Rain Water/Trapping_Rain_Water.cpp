class Solution {
public:
    int trap(vector<int>& height) {
        int hL = height.size();
        int total = 0;
        
        vector<int> leftHighBar(hL, 0);
        vector<int> rightHighBar(hL, 0);
        
        leftHighBar[0] = height[0];
        rightHighBar[hL-1] = height[hL-1];
        
        for(int i = 1; i < hL; i++){
            leftHighBar[i] = max(height[i], leftHighBar[i-1]);
        }
        
        for(int i = hL-2; i >= 0; i--){
            rightHighBar[i] = max(height[i], rightHighBar[i+1]);
        }
        
        for(int i = 0; i < hL; i++){
            if(rightHighBar[i] > height[i] && leftHighBar[i] > height[i]){
                int validHeight = rightHighBar[i] > leftHighBar[i] ? leftHighBar[i] : rightHighBar[i];
                total += (validHeight - height[i]);
            }
        }
        
        return total;
    }
};