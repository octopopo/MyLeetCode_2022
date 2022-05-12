class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int cL = cost.size();
        vector<int> record(cL+1, 0);
        record[0] = cost[0];
        record[1] = cost[1];
        
        for(int i = 2; i < cL; i++){
            record[i] = record[i-1] > record[i-2] ? record[i-2] : record[i-1];
            record[i] += cost[i];
        }
        
        record[cL] = record[cL-1] > record[cL-2] ? record[cL-2] : record[cL-1];
        
        return record[cL];
    }
};