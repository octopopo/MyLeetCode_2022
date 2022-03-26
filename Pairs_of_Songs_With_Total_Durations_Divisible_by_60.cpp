class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int res = 0;
        int tL = time.size();
        unordered_map<int, int> timeAppearL;
        unordered_map<int, int> timeAppearM;
        int thirtyTimes = 0;
        int sixtyTimes = 0;
        int remain;
        
        for(int i = 0; i < tL; i++){
            time[i] = time[i]%60;
            if(time[i] == 30){
                thirtyTimes++;
            }
            if(time[i] == 0){
                sixtyTimes++;
            }
            else if(time[i] < 30){
                timeAppearL[time[i]]++;
            }
            else{
                timeAppearM[time[i]]++;
            }
        }
        
        for(pair<int, int> firstPair : timeAppearL){
            remain = 60 - firstPair.first;
            if(timeAppearM.count(remain)){
                res += (firstPair.second * timeAppearM[remain]);
            }
        }
        if(thirtyTimes >= 2){
            res = thirtyTimes%2 == 0 ? res + (thirtyTimes-1) * (thirtyTimes / 2) : res + ((thirtyTimes-1)/2) * thirtyTimes;
        }
        
        if(sixtyTimes >= 2){
            res = sixtyTimes%2 == 0 ? res + (sixtyTimes-1) * (sixtyTimes / 2) : res + ((sixtyTimes-1)/2) * sixtyTimes;
        }
        
        return res;
    }
};