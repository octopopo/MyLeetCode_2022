class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int totalSeats = 2*n;
        unordered_map<int, vector<bool>> rowRecord;
        
        for(vector<int>& reserve : reservedSeats){
            if(shouldDeduct(rowRecord, reserve[1], reserve[0])){
                totalSeats--;
            }
        }
        
        return totalSeats;
    }
    
    
    bool shouldDeduct(unordered_map<int, vector<bool>>& record, int seatNum, int rowNum){
        if(!record.count(rowNum)){
            record[rowNum] = vector<bool>(3, false);
        }
        if(seatNum == 1 || seatNum == 10){
            return false;
        }
        
        if(record[rowNum][0] && record[rowNum][1] && record[rowNum][2]){
            return false;
        }
        if(seatNum <= 3){
            if(record[rowNum][0]){
                return false;
            }
            
            if(!record[rowNum][0] && !record[rowNum][1] && !record[rowNum][2]){
                record[rowNum][0] = true;
                return true;
            }
            if(record[rowNum][1] && record[rowNum][2]){
                record[rowNum][0] = true;
                return true;
            }
            record[rowNum][0] = true;
            return false;
        }
        else if(seatNum >= 8){
            if(record[rowNum][2]){
                return false;
            }
            if(!record[rowNum][0] && !record[rowNum][1] && !record[rowNum][2]){
                record[rowNum][2] = true;
                return true;
            }
            if(record[rowNum][1] && record[rowNum][0]){
                record[rowNum][2] = true;
                return true;
            }
            
            record[rowNum][2] = true;
            return false;
        }
        else if(seatNum >= 4 && seatNum <= 5){
            if(!record[rowNum][0] && !record[rowNum][1]){
                record[rowNum][0] = true;
                record[rowNum][1] = true;
                return true;
            }
            else{
                record[rowNum][0] = true;
                record[rowNum][1] = true;
                if(record[rowNum][2]){
                    return true;
                }
                return false;
            }
        }
        else if(seatNum >= 6 && seatNum <= 7){
            if(!record[rowNum][2] && !record[rowNum][1]){
                record[rowNum][2] = true;
                record[rowNum][1] = true;
                return true;
            }
            else{
                record[rowNum][2] = true;
                record[rowNum][1] = true;
                if(record[rowNum][0]){
                    return true;
                }
                return false;
            }
        }
        return false;
    }
};