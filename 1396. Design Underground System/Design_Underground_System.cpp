class UndergroundSystem {
    class CheckIn{
        public:
        string startStation;
        int checkInTime;
        
        CheckIn(string start, int time){
            startStation = start;
            checkInTime = time;
        }
    };
    
    class TimeTrack{
        public: 
        int visitTimes;
        int totalTime;
        
        TimeTrack(int visit, int total){
            visitTimes = visit;
            totalTime = total;
        }
    };
public:
    unordered_map<int, CheckIn*> customerToStart;
    unordered_map<string, unordered_map<string, TimeTrack*>> startToEndTime;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        if(customerToStart.count(id)){
            return;
        }
        customerToStart[id] = new CheckIn(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        int checkInTime = customerToStart[id]->checkInTime;
        string start = customerToStart[id]->startStation;
        if(startToEndTime.count(start) && startToEndTime[start].count(stationName)){
            startToEndTime[start][stationName]->visitTimes++;
            startToEndTime[start][stationName]->totalTime+=(t-checkInTime);
        }
        else{
            startToEndTime[start][stationName] = new TimeTrack(1, t-checkInTime);
        }
        customerToStart.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        int visit = startToEndTime[startStation][endStation]->visitTimes;
        int total = startToEndTime[startStation][endStation]->totalTime;
        
        return (double)total/visit;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */