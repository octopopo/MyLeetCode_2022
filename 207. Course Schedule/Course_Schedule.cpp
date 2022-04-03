class Solution {
public:
    
    int findCourseToTake(unordered_map<int, set<int>>& courseToPre){
        int nextCourse;
        for(const pair<int, set<int>>& cPair : courseToPre){
            //If you find a course with no prerequisites left, return the course number
            if(cPair.second.size() == 1){
                nextCourse = cPair.first;
                courseToPre.erase(nextCourse);
                return nextCourse;
            }
        }
        
        //If you can't find any course that has no prerequisites left
        return -1;
    }
    
    void removeTakenCourseFromPrerequisites(unordered_map<int, set<int>>& courseToPre, int takeCourse){
        for(unordered_map<int, set<int>>::iterator it = courseToPre.begin(); it != courseToPre.end(); it++){
            if(it->second.count(takeCourse)){
                it->second.erase(takeCourse);
            }
        }
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,set<int>> courseToPre;
        int courseTaken = 0;
        
        int pL = prerequisites.size();
        
        for(int i = 0; i < numCourses; i++){
            courseToPre[i].insert(-1);
        }
        
        //Build the map with prerequisites
        for(int i = 0; i < pL; i++){
            courseToPre[prerequisites[i][0]].insert(prerequisites[i][1]);
        }
        
        int nextCourse = findCourseToTake(courseToPre);
        while(nextCourse != -1){
            //cout << nextCourse << endl;
            courseTaken++;
            if(courseTaken >= numCourses){
                break;
            }
            removeTakenCourseFromPrerequisites(courseToPre, nextCourse);
            nextCourse = findCourseToTake(courseToPre);
        }
        
        return courseTaken == numCourses;
        
    }
};