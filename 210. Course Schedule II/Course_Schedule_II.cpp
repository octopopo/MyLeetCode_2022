class Solution {
public:
    struct Course{
        int id;
        set<int> pre;
        
        Course(int i){
            id = i;
        }
    };
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, Course*> courseMap;
        vector<int> result(numCourses, 0);
        for(int i = 0; i < numCourses; i++){
            courseMap[i] = new Course(i);
        }
        
        for(int i = 0; i < prerequisites.size(); i++){
            vector<int>* preList = &prerequisites[i];
            //cout << preList->at(0) << " " << preList->at(1) << endl;
            courseMap[preList->at(0)]->pre.insert(preList->at(1));
        }
        
        for(int i = 0; i < numCourses; i++){
            int temp = pickFirstValidCourse(courseMap);
            if(temp == -1){
                vector<int> emp;
                return emp;
            }
            refreshPreInCourse(temp, courseMap);
            result[i] = temp;
        }
        
        return result;
    }
    
    int pickFirstValidCourse(unordered_map<int, Course*>& courseMap){
        for(pair<int, Course*> coursePair : courseMap){
            if(coursePair.second->pre.empty()){
                return coursePair.first;
            }
        }
        
        return -1;
    }
    
    void refreshPreInCourse(int taken, unordered_map<int, Course*>& courseMap){
        for(pair<int, Course*> coursePair : courseMap){
            if(coursePair.second->pre.count(taken)){
                coursePair.second->pre.erase(taken);
            }
        }
        courseMap.erase(taken);
    }
};