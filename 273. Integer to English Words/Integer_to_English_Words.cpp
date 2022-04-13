class Solution {
public:
    string numberFromOneToNine(int num){
        switch(num){
            case 1:
                return "One";
            case 2:
                return "Two";
            case 3:
                return "Three";
            case 4:
                return "Four";
            case 5:
                return "Five";
            case 6:
                return "Six";
            case 7:
                return "Seven";
            case 8:
                return "Eight";
            case 9:
                return "Nine";
            default:
                return "wrong";
        }
    }
    
    string numberFromTenToNineTeen(int num){
        switch(num){
            case 10:
                return "Ten";
            case 11:
                return "Eleven";
            case 12:
                return "Twelve";
            case 13:
                return "Thirteen";
            case 14:
                return "Fourteen";
            case 15:
                return "Fifteen";
            case 16:
                return "Sixteen";
            case 17:
                return "Seventeen";
            case 18:
                return "Eighteen";
            case 19:
                return "Nineteen";
            default:
                return "wrong";
        }
    }
    
    string numberFromTwentyToNinety(int num){
        switch(num){
            case 2:
                return "Twenty";
            case 3:
                return "Thirty";
            case 4:
                return "Forty";
            case 5:
                return "Fifty";
            case 6:
                return "Sixty";
            case 7:
                return "Seventy";
            case 8:
                return "Eighty";
            case 9:
                return "Ninety";
            default:
                return "wrong";
        }
    }
    
    string numberLessThanHundred(int num){
        if(num == 0){
            return "Zero";
        }
        
        if(num < 10){
            return numberFromOneToNine(num);
        }
        else if(num < 20){
            return numberFromTenToNineTeen(num);
        }
        
        string result = "";
        
        int lastDigit = num%10;
        int ten = num/10;
        
        result += numberFromTwentyToNinety(ten);
        
        if(lastDigit != 0){
            result += (" " + numberFromOneToNine(lastDigit));
        }
        return  result;
    }
    
    string numberLessThanThousand(int num){
        if(num < 100){
            return numberLessThanHundred(num);
        }
        
        int hundred = num/100;
        int remain = num - hundred * 100;
        
        
        string s = numberFromOneToNine(hundred) + " Hundred";
        
        if(remain != 0){
            s += " " + numberLessThanHundred(remain);
        }
        return s;
    }
    
    string numberToWords(int num) {
        if(num == 0){
            return "Zero";
        }
        
        int billion = num / 1000000000;
        int million = (num - billion * 1000000000) / 1000000;
        int thousand = (num - billion * 1000000000 - million * 1000000) / 1000;
        int remain = (num - billion * 1000000000 - million * 1000000 - thousand * 1000);
        
        
        string result = "";
        if(billion != 0){
            result += numberLessThanThousand(billion) + " Billion";
        }
        
        if(million != 0){
            if(result != ""){
                result += " ";
            }
            result += numberLessThanThousand(million) + " Million";
        }
        
        if(thousand != 0){
            if(result != ""){
                result += " ";
            }
            result += numberLessThanThousand(thousand) + " Thousand";
        }
        
        if(remain != 0){
            if(result != ""){
                result += " ";
            }
            result += numberLessThanThousand(remain);
        }
        
        return result;
    }
};