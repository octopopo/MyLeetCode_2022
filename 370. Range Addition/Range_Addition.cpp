class Solution {
public:

    vector<int>* result;
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        int uL = updates.size();
        result = new vector<int>(length, 0);

        for(int i = 0; i < uL; i++){
            vector<int>* temp = &updates[i];
            int val = (*temp)[2];
            int startPos = (*temp)[0];
            int endPos = (*temp)[1];
            (*result)[startPos] += val;
            if(endPos < length - 1){
                (*result)[endPos+1] -= val;
            }
        }
        
        
        for(int i = 1; i < length; i++){
            (*result)[i] += (*result)[i-1];
        }
        
        return *result;
    }
};