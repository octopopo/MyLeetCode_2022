class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b){
        if(a[1] > b[1]){
            return true;
        }
        else{
            return false;
        }
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int maxUnits = 0;
        int boxIndex = 0;
        
        while(truckSize >= 0 && boxIndex < boxTypes.size()){
            if(truckSize <= boxTypes[boxIndex][0]){
                maxUnits += truckSize * boxTypes[boxIndex][1];
                break;
            }
            maxUnits += boxTypes[boxIndex][0] * boxTypes[boxIndex][1];
            truckSize -= boxTypes[boxIndex][0];
            boxIndex++;
        }
        
        
        return maxUnits;
    }
};