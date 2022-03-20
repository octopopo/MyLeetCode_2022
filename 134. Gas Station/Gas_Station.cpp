class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalStation = gas.size();
        
        int totalGas = 0;
        int currentGas = 0;
        int startingStation = 0;
        
        for(int i = 0; i < totalStation; i++){
            totalGas += (gas[i] - cost[i]);
            currentGas += (gas[i] - cost[i]);
            if(currentGas < 0){
                startingStation = i+1;
                currentGas = 0;
            }
        }
        
        return totalGas >= 0 ? startingStation : -1;
    }
};