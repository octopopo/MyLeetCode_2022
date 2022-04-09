class HitCounter {
public:
    deque<pair<int, int>> mQueue; 
    int maxInterval = 300;
    int total = 0;
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        if(mQueue.empty() || mQueue.back().first != timestamp){
            mQueue.push_back(make_pair(timestamp, 1));
        }
        else{
            mQueue.back().second++;
        }
        total++;
    }
    
    int getHits(int timestamp) {
        int bound = timestamp-maxInterval;
        pair<int, int> frontP;
        while(!mQueue.empty() && mQueue.front().first <= bound){
            frontP = mQueue.front();
            mQueue.pop_front();
            total -= frontP.second;
        }
        return total;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */