class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int nodeCount = pid.size();
        unordered_map<int, vector<int>> nodeNumToChildren;
        int parentNum;
        vector<int> res;
        queue<int> nodeQ;
        int qSize;
        int qF;
        int cPtr;

        
        //reverse ppid list, so we can get record of what children are under targetnode.
        for(int i = 0; i < nodeCount; i++){
            parentNum = ppid[i];
            nodeNumToChildren[parentNum].push_back(pid[i]);
        }
        
        res.push_back(kill);
        //if kill is not in the map that means target has no children, return with only itself
        if(!nodeNumToChildren.count(kill)){
            return res;
        }
        
        //Go through child
        nodeQ.push(kill);
        
        while(!nodeQ.empty()){
            qSize = nodeQ.size();
            for(int i = 0; i < qSize; i++){
                qF = nodeQ.front();
                nodeQ.pop();
                for(int j = 0; j < nodeNumToChildren[qF].size(); j++){
                    cPtr = nodeNumToChildren[qF][j];
                    res.push_back(cPtr);
                    if(nodeNumToChildren.count(cPtr)){
                        nodeQ.push(cPtr);
                    }
                }
            }
        }
        
        return res;
    }
};