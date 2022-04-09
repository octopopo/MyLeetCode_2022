class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res {0, 1};
        int power2 = 2;
        int rL;
        n -= 1;
        while(n > 0){
            rL = res.size();
            
            for(int i = rL-1; i >= 0; i--){
                res.push_back(res[i] + power2);
            }
            
            power2 *= 2;
            n--;
        }
        
        return res;
    }
};