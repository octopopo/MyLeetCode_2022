class Solution {
public:
    struct VisitMove{
        string username;
        int timestamp;
        string website;
    };
    
    static bool compare(VisitMove a, VisitMove b){
        if(a.timestamp < b.timestamp){
            return true;
        }
        return false;
    }
    
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        vector<VisitMove> record;
        unordered_map<string, vector<VisitMove>> userToVisit;
        vector<string> res;
        
        //Sort the data by timestamp
        for(int i = 0; i < username.size(); i++){
            VisitMove move;
            move.username = username[i];
            move.timestamp = timestamp[i];
            move.website = website[i];
            record.push_back(move);
        }
        
        sort(record.begin(), record.end(), compare);
        
        //separate the moves by users
        for(int i = 0; i < record.size(); i++){
            userToVisit[record[i].username].push_back(record[i]);
        }
        
        unordered_map<string, pair<string, int>> patternToLastVisitAndCount;
        int maxCount = 0;
        string ans = "";
        
        for(pair<string, vector<VisitMove>> singleUser : userToVisit){
            string user = singleUser.first;
            int n = singleUser.second.size();
            vector<VisitMove> visits = singleUser.second;
            
            //This is the way to generate all possibility
            for(int i = 0; i < n-2; i++){
                for(int j = i+1; j < n-1; j++){
                    for(int k = j+1; k < n; k++){
                        string pattern = visits[i].website + "," + visits[j].website + "," + visits[k].website;
                        
                        //cout << pattern << endl;
                        
                        if(!patternToLastVisitAndCount.count(pattern)){
                            patternToLastVisitAndCount[pattern].first = user;
                            patternToLastVisitAndCount[pattern].second = 1;
                        }
                        else{
                            //cout << pattern << endl;
                            //this is to avoid counting same pattern for same user twice
                            if(patternToLastVisitAndCount[pattern].first != user){
                                patternToLastVisitAndCount[pattern].first = user;
                                patternToLastVisitAndCount[pattern].second++;
                            }
                        }
                        
                        if(patternToLastVisitAndCount[pattern].second > maxCount){
                            maxCount = patternToLastVisitAndCount[pattern].second;
                            ans = pattern;
                        }
                        else if(patternToLastVisitAndCount[pattern].second == maxCount){
                            if(ans > pattern){
                                //cout << "pattern: " << pattern << endl;
                                //cout << "ans: " << ans << endl;
                                ans = pattern;
                            }
                        }
                    }
                }
            }
        }
        
       // cout << ans << endl;
        
        string temp = "";
        for(int i = 0; i < ans.size(); i++){
            if(ans[i] == ','){
                res.push_back(temp);
                temp = "";
                continue;
            }
            temp += ans[i];
        }
        
        res.push_back(temp);
        
        return res;
    }
};