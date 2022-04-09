class Solution {
public:
    int squareDis(vector<int>& point){
        return point[0] * point[0] + point[1] * point[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<int, int>> pq;
        int pL = points.size();
        
        for(int i = 0; i < k; i++){
            pair<int, int> tP = {squareDis(points[i]), i};
            pq.push(tP);
        }
        
        for(int i = k; i < pL; i++){
            int dis = squareDis(points[i]);
            if(dis < pq.top().first){
                pq.pop();
                pair<int, int> tP = {dis, i};
                pq.push(tP);
            }
        }
        
        while(!pq.empty()){
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        
        return res;
    }
};