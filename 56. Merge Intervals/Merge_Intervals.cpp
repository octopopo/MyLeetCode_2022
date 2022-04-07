class Solution {
public:
    static bool compare(vector<int>& a, vector<int>&b){
        if(a[0] == b[0]){
            if(a[1] < b[1]){
                return true;
            }
            return false;
        }
        if(a[0] < b[0]){
            return true;
        }
        
        return false;
        
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int iL = intervals.size();
        
        int begin;
        int end;
        //Sort the array with the begin and end
        sort(intervals.begin(), intervals.end(), compare);
        
        begin = intervals[0][0];
        end = intervals[0][1];
        
        for(int i = 1; i < iL; i++){
            if(intervals[i][0] <= end){
                if(intervals[i][1] > end){
                    end = intervals[i][1];
                }
            }
            else{
                res.push_back(vector<int>{begin, end});
                begin = intervals[i][0];
                end = intervals[i][1];
            }
        }
        
        res.push_back(vector<int>{begin, end});
        
        
        return res;
    }
};