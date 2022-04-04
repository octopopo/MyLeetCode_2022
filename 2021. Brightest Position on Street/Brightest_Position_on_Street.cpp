class Solution {
public:
    /*static bool compare(void* a, void* b){
        return *(vector<int>*)a[0] > *(vector<int>*)b[0]; 
    }*/
    int brightestPosition(vector<vector<int>>& lights) {
        //transfer the light data to min pot to max pos
        int midPos;
        int range;
        priority_queue<int, vector<int>, greater<int>> startPosQ;
        priority_queue<int, vector<int>, greater<int>> endPosQ;
        int maxBright = 0;
        int lightPos = 0;
        int brightCount = 0;
        int sTop, eTop = 0;
        for(vector<int>& light : lights){
            midPos = light[0];
            range = light[1];
            
            startPosQ.push(midPos-range);
            endPosQ.push(midPos+range);
        }
        
        while(!startPosQ.empty()){
            if(!startPosQ.empty() && !endPosQ.empty()){
                sTop = startPosQ.top();
                eTop = endPosQ.top();
                if(sTop <= eTop){
                    startPosQ.pop();
                    brightCount++;
                    if(brightCount > maxBright){
                        maxBright = brightCount;
                        lightPos = sTop;
                    }
                }
                else{
                    endPosQ.pop();
                    brightCount--;
                }
            }
        }
        
        return lightPos;
    }
};