class Solution {
public:
    int getVal(char c) {
        switch(c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
    int romanToInt(string s) {
        int n = s.size();
        int total = getVal(s[n-1]);

        for(int i=n-2;i>=0;i--) {
            int curr = getVal(s[i]);
            int next = getVal(s[i+1]);

            if(curr<next) {
                total -= curr;
            } else {
                total += curr;
            }
        }
        return total;
    }
};