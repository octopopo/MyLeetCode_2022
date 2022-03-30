class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long int minSum = 0;
        stack<int> minStack;
        int mid, rightCount, leftCount;
        arr.push_back(INT_MIN);
        
        for(int i = 0; i < arr.size(); i++){
            while(!minStack.empty() && arr[i] <= arr[minStack.top()]){
                mid = minStack.top();
                rightCount = i-mid;
                minStack.pop();
                leftCount = mid - (minStack.empty() ? -1 : minStack.top());
                minSum += (long long int)rightCount * (long long int)leftCount * arr[mid];
            }
            minStack.push(i);
        }
        
        //cout << to_string(minSum) << endl;
        
        return minSum > INT_MAX ? int(minSum % 1000000007) : (int)minSum;
    }
};