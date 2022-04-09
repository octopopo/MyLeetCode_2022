class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0){
            return 0;
        }
        
        vector<int> record(amount+1, INT_MAX);
        int cL = coins.size();
        
        for(int i = 0; i < cL; i++){
            if(coins[i] > amount){
                continue;
            }
            record[coins[i]] = 1;
        }
        
        record[0] = 0;
        int tempM;
        int tempR = INT_MAX;
        
        for(int i = 0; i <= amount; i++){
            if(record[i] == 1){
                continue;
            }
            else{
                for(int j = 0; j < cL; j++){
                    tempM = i - coins[j];
                    if(tempM > 0 && record[tempM] != -1){
                        record[i] = min(record[i] ,record[tempM] + 1);
                    }
                }
                if(record[i] == INT_MAX){
                    record[i] = -1;
                }
            }
        }
        
        return record[amount];
    }
};