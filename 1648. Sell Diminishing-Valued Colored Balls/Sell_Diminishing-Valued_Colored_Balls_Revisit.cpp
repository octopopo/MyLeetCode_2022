class Solution {
public:
    int modulo = 1000000007;
    long long sumFromNtoX(long long x, long long n){
        return (n * (n+1) / 2 - x * (x+1)/2)%modulo;
    }
    static bool compare(int a, int b){
        return a > b;
    }
    int maxProfit(vector<int>& inventory, int orders) {
        sort(inventory.begin(), inventory.end(), compare);
        
        int coCount = 0;
        long long curHighPrice;
        long long nextHighPrice;
        long long sum = 0;
        
        
        coCount = 1;
        curHighPrice = inventory[0];
        
        for(int i = 1; i < inventory.size(); i++){
            if(inventory[i] == curHighPrice){
                coCount++;
            }
        }
        
        nextHighPrice = coCount >= inventory.size() ? 0 : inventory[coCount];
        
        //cout << "curH " << curHighPrice << " nextH " << nextHighPrice << " coC " << coCount;
        
        while(orders > (curHighPrice - nextHighPrice) * coCount){
            
            sum += (sumFromNtoX(nextHighPrice, curHighPrice) * coCount) % modulo;
            
            orders -= (curHighPrice-nextHighPrice) * coCount;
            
            curHighPrice = nextHighPrice;
            
            for(int i = coCount; i < inventory.size(); i++){
                if(inventory[i] == curHighPrice){
                    coCount++;
                }
            }
            
            nextHighPrice = coCount >= inventory.size() ? 0 : inventory[coCount];
        }
        
        int q = orders/coCount;
        int r = orders%coCount;
        
        
        sum += (sumFromNtoX(curHighPrice-q, curHighPrice) * coCount) % modulo;
        
        sum += ((curHighPrice-q) * r)%modulo;
        
        
        return sum % modulo;
    }
};