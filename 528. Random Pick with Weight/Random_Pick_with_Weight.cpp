class Solution {
public:
    int totalWeight = 0;
    int wL = 0;
    vector<int>* wDup;
    Solution(vector<int>& w) {
        wDup = &w;
        wL = w.size();
        for(int i = 1; i < wL; i++){
            w[i] += w[i-1];
        }
        totalWeight = w[wL-1];
    }
    
    int pickIndex() {
        int pick = rand()%totalWeight;
        if(pick < (*wDup)[0]){
            return 0;
        }
        for(int i = 1; i < wL; i++){
            if(pick >= (*wDup)[i-1] && pick < (*wDup)[i]){
                return i;
            }
        }
        return wL-1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */