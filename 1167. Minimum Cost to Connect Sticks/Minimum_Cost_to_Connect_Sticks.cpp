class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        int sL = sticks.size();
        
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0 ; i < sL; i++){
            pq.push(sticks[i]);
        }
        
        int num1, num2;
        int temp;
        int sum = 0;
        
        while(pq.size() >=2){
            num1 = pq.top();
            pq.pop();
            num2 = pq.top();
            pq.pop();
            temp = num1+num2;
            pq.push(temp);
            sum += temp;
        }
        
        return sum;
    }
};