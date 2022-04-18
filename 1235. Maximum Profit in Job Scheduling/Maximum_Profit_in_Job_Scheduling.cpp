class Solution {
public:
    class Job{
        public: 
        int start;
        int end;
        int profit;
        
        bool operator()(Job& a, Job& b){
            return a.start > b.start;
        }
    };
    
    //unordered_map<int, vector<Job>> endTimeToJob;
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int pL = profit.size();
        priority_queue<Job, vector<Job>, Job> pq;
        int highestEnd = 0;
        int tempEnd;
        int currentProfit = 0;
        //Build the map with 
        for(int i = 0; i < pL; i++){
            tempEnd = endTime[i];
            Job newJob;
            newJob.start = startTime[i];
            newJob.end = tempEnd;
            newJob.profit = profit[i];
            //endTimeToJob[tempEnd].push_back(newJob);
            highestEnd = max(highestEnd, tempEnd);
            pq.push(newJob);
        }
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> aPq;
        int maxProfit = 0;
        
        while(!pq.empty()){
            Job topJ = pq.top();
            pq.pop();
            
            while(!aPq.empty() && topJ.start >= aPq.top()[0]){
                maxProfit = max(maxProfit, aPq.top()[1]);
                aPq.pop();
            }
            
            aPq.push({topJ.end, topJ.profit + maxProfit});
            
        }
        
        while(!aPq.empty()){
            maxProfit = max(maxProfit, aPq.top()[1]);
            aPq.pop();
        }
        
        return maxProfit;
    }
};