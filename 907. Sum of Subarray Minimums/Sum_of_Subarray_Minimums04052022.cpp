class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> minStack;
        unordered_map<int, int> valToPos;
        long long res = 0;
        arr.push_back(0);
        
        for(int i = 0; i < arr.size(); i++){
            while(!minStack.empty() && minStack.top() >= arr[i]){
                int val = minStack.top();
                //cout << val << endl;
                int mid = valToPos[val];
                long long right = i-mid;
                minStack.pop();
                int leftBound = minStack.empty() ? -1 : valToPos[minStack.top()];
                long long left = mid-leftBound;
                res += val * right * left;
            }
            
            valToPos[arr[i]] = i;
            minStack.push(arr[i]);
        }
        
        return res%1000000007;
    }
};