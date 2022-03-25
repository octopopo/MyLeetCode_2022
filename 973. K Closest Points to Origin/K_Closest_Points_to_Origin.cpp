class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> maxPQ;
        vector<vector<int>> res;
        
        for(int i = 0; i < k; i++){
            pair<int, int> entry = {squareDist(points[i]), i};
            maxPQ.push(entry);
        }
        
        for(int i = k; i < points.size(); i++){
            pair<int, int> entry = {squareDist(points[i]), i};
            if(entry.first < maxPQ.top().first){
                maxPQ.pop();
                maxPQ.push(entry);
            }
        }
        
        while(!maxPQ.empty()){
            int entryIndex = maxPQ.top().second;
            maxPQ.pop();
            res.push_back(points[entryIndex]);
        }
        
        return res;
    }
    
    int squareDist(vector<int>& point){
        return point[0] * point[0] + point[1] * point[1];
    }
};