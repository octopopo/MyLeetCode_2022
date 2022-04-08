class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyP = prices[0];
        int sellP = prices[0];
        int maxPro = 0;
        int pL = prices.size();
        
        
        for(int i = 1; i < pL; i++){
            if(prices[i] < buyP){
                buyP = prices[i];
                sellP = prices[i];
            }
            
            if(prices[i] > sellP){
                sellP = prices[i];
                maxPro = max(maxPro, sellP - buyP);
            }
        }
        
        return maxPro;
        
    }
};