class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int dL = days.size();
        int dPtr = 0;
        int lastDay = days[dL-1];
        
        vector<int> record(lastDay+1, 365000);
        
        record[0] = 0;
        
        for(int i = 1; i <= lastDay; i++){
            if(i == days[dPtr]){
                record[i] = min(record[i], costs[0] + record[i-1]);
                record[i] = min(record[i], costs[1] + record[(i-7 >= 0 ? i-7 : 0)]);
                record[i] = min(record[i], costs[2] + record[(i-30 >= 0 ? i-30 : 0)]);
                dPtr++;
            }
            else{
                record[i] = record[i-1];
            }
        }
        
        return record[lastDay];
    }
};