class Solution {
public:
    unordered_map<char, int> charAppear;
    string originalDigits(string s) {
        int sL = s.size();
        vector<int> record(10, 0);
        string res = "";
        
        for(int i = 0; i < sL; i++){
            charAppear[s[i]]++;
        }
        
        if(charAppear.count('z')){
            record[0] = charAppear['z'];
        }
        
        if(charAppear.count('w')){
            record[2] = charAppear['w'];
        }
        
        if(charAppear.count('u')){
            record[4] = charAppear['u'];
        }
        
        if(charAppear.count('x')){
            record[6] = charAppear['x'];
        }
        
        if(charAppear.count('g')){
            record[8] = charAppear['g'];
        }
        
        if(charAppear.count('s')){
            record[7] = charAppear['s'] - record[6]; //because 7 and 6 share 's'
        }
        
        if(charAppear.count('f')){
            record[5] = charAppear['f'] - record[4]; //because 5 and 4 share 'f'
        }
        
        if(charAppear.count('h')){
            record[3] = charAppear['h'] - record[8]; //because 3 and 8 share 'h'
        }
        
        if(charAppear.count('i')){
            record[9] = charAppear['i'] - record[5] - record[6] - record[8]; //because 9, 5, and 6 share i
        }
        
        if(charAppear.count('o')){
            record[1] = charAppear['o'] - record[0] - record[2] - record[4];
        }
        
        for(int i = 0; i <= 9; i++){
            if(record[i] > 0){
                for(int j = 0; j < record[i]; j++){
                    res += to_string(i);
                }
            }
        }
        
        return res;
    }
};


//one

//nine


//two   w
//eight g
//zero  z
//six   x
//four u
//seven s
//five
//three