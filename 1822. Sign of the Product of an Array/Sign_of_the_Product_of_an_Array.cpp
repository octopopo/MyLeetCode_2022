class Solution {
public:
    int arraySign(vector<int>& nums) {
        int minCount = 0;
        int zCount = 0;
        
        for(int i : nums){
            if(i < 0){
                minCount++;
            }
            else if(i == 0){
                zCount++;
            }
        }
        
        if(zCount > 0){
            return 0;
        }
        
        return minCount%2 == 0 ? 1 : -1;
    }
};