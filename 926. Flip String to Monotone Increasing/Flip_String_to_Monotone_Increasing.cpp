class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int sL = s.size();
        if(sL == 1){
            return 0;
        }
        vector<int> makeLeftZ(sL, 0);
        vector<int> makeRightO(sL, 0);
        
        makeLeftZ[0] = s[0] - '0';
        int minF = INT_MAX;
        
        for(int i = 1; i < sL; i++){
            makeLeftZ[i] = makeLeftZ[i-1] + (s[i] - '0');
        }
        
        makeRightO[sL-1] = s[sL-1] == '0' ? 1 : 0;
        
        for(int i = sL-2; i>= 0; i--){
            makeRightO[i] = s[i] == '0' ? makeRightO[i+1] + 1 : makeRightO[i+1];
        }
        
        minF = makeRightO[0];
        for(int i = 1; i < sL-1; i++){
            //cout << "i: " << i << " makeRightO: " << makeRightO[i+1] << " makeLeftZ: " << makeLeftZ[i-1] << endl;
            minF = min(minF, (makeRightO[i+1] + makeLeftZ[i-1]));
        }
        minF = min(minF, makeLeftZ[sL-1]);
        
        return minF;
    }
};