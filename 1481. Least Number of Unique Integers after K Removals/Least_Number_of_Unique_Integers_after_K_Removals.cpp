class Solution {
public:
    class sortMap{
        public:
        bool operator()(pair<int, int>& a, pair<int, int>& b){
            return a.second > b.second;
        }
    };
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> numToCount;
        int aL = arr.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, sortMap> pq;
        pair<int,int> topPair;
        
        for(int i = 0; i < aL; i++){
            numToCount[arr[i]]++;
        }
        
        int totalUnique = numToCount.size();
        
        for(const pair<int,int> p : numToCount){
            pq.push(p);
        }
        
        while(k >= 0 && !pq.empty()){
            topPair = pq.top();
            pq.pop();
            if(k >= topPair.second){
                totalUnique--;
                k-=topPair.second;
            }
            else{
                break;
            }
        }
        
        return totalUnique;
        
    }
};