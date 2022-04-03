class Solution {
public:
    class PairCompare{
        public:
        bool operator()(pair<string, int>& a, pair<string, int>& b){
            return b.second >= a.second;
        }
    };
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<string, int>, vector<pair<string,int>>, PairCompare> pq;
        string res = "";
        pair<string, int> aP = make_pair("a", a);
        pair<string, int> bP = make_pair("b", b);
        pair<string, int> cP = make_pair("c", c);
        
        pair<string, int> longest, secondLong, smallest;
        
        if(a != 0){
            pq.push(aP);    
        }
        if(b != 0){
            pq.push(bP);
        }
        if(c != 0){
            pq.push(cP);
        }
        
        while(!pq.empty()){
            longest = pq.top();
            pq.pop();
            
            if(longest.second >= 2){
                int rL = res.size();
                if(rL >= 2 && res[rL-1] == longest.first[0] && res[rL-2] == longest.first[0]){
                    if(!pq.empty()){
                        secondLong = pq.top();
                        pq.pop();
                        res += secondLong.first;
                        secondLong.second--;
                        if(secondLong.second > 0){
                            pq.push(secondLong);    
                        }
                        pq.push(longest);
                    }
                }
                else if(rL >= 2 && res[rL-1] == longest.first[0]){
                    res += longest.first;
                    longest.second--;
                    if(!pq.empty()){
                        secondLong = pq.top();
                        pq.pop();
                        res += secondLong.first;
                        secondLong.second--;
                        if(secondLong.second > 0){
                            pq.push(secondLong);    
                        }
                        pq.push(longest);
                    }
                }
                else{
                    res += (longest.first +longest.first);
                    longest.second -= 2;
                    if(!pq.empty()){
                        secondLong = pq.top();
                        pq.pop();
                        res += secondLong.first;
                        secondLong.second--;
                        if(secondLong.second > 0){
                            pq.push(secondLong);    
                        }
                    }
                    if(longest.second > 0){
                        pq.push(longest);
                    }
                }
            }
            else{
                int rL = res.size();
                if(rL >= 2 && res[rL-1] == longest.first[0] && res[rL-2] == longest.first[0]){
                    continue;
                }
                res += longest.first;
                longest.second--;
            }
        }
        
        return res;
    }
};