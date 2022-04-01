class Solution {
public:
    static bool compare(int& a, int& b){
        return a > b;
    }
    int maxProfit(vector<int>& inventory, int orders) {
        sort(inventory.begin(), inventory.end(), compare);
        
        int iL = inventory.size();
        int countAtSame = 1;
        long long height;
        long long lower;
        long long sum = 0;
        int mod = 1000000007;
        
        for(int i = 0; i < iL; i++){
            //cout << "orders: " << orders << endl;
            //cout << "sum: " << sum << endl;
            //If two different colors ball have same amount, they can be counted at the same time
            if(i == iL -1){
                //cout <<"herehasdfads" << endl;
                height = inventory[i];
                lower = 1;
            }
            else{
                while(i+1 < iL &&  inventory[i] == inventory[i+1]){
                    i = i+1;
                }
                
                if(i == iL-1){
                    height = inventory[i];
                    lower = 1;
                }
                else{
                    height = inventory[i] - inventory[i+1];
                    lower = inventory[i+1] + 1;
                }
            }
            
            //cout << height << endl;
            
            if(orders >= height * (i+1)){
                //cout << "here" << endl;
                sum = (sum + ((inventory[i] + lower) * (i+1) * height / 2))%mod;
                orders -= (height * (i+1));
                //cout << orders <<"-------" << endl;
            }
            else{
                int d = orders/(i+1);
                int q = orders%(i+1);
                
                //cout <<"q: " << q << " d: " << d << endl;
                
                lower = inventory[i] - d;
                
                //cout << sum << endl;
                sum = (sum + ((inventory[i] + lower+1) * (i+1) * d / 2))%mod;
                
                sum = (sum + (lower * q))%mod;
                break;
            }
        }
        
        return sum;
    }
};
//This question is really tricky, you can count multiple element at the same time
//Also we can insert a 0 at the back of the vector to save the time we used for checking if it is the end of the array