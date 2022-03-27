class Solution {
public:
    bool isRobotBounded(string instructions) {
        //This question is kind of like a mathemetic question,
        //So after one pass of the instruction, if robot still facing 
        //north and doesn't come back to the point, it meanse that the robot won't come back
        vector<vector<int>> directions = {{0,1}, {-1, 0}, {0, -1}, {1, 0}};
        vector<int> position = {0, 0};
        int currentDir = 0;
        
        for(char step : instructions){
            if(step == 'G'){
                position[0] += directions[currentDir][0];
                position[1] += directions[currentDir][1];
            }
            else if(step == 'L'){
                currentDir = (currentDir+1)%4;
            }
            else if(step == 'R'){
                currentDir = (currentDir+3)%4;
            }
        }
        
        return (position[0] == 0 && position[1] == 0) || currentDir != 0;
    }
    
};