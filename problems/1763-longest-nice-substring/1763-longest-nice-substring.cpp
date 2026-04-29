class Solution {
public:
    string longestNiceSubstring(string s) {
        if(s.length() < 2) return "";

        uint32_t lowMask = 0, highMask = 0;
        for(char c:s) {
            if(islower(c)) lowMask |= (1 << (c - 'a'));
            else highMask |= (1 << (c - 'A'));
        }
        uint32_t badChar = lowMask ^ highMask;

        if(badChar == 0) return s;

        for(int i=0;i<s.size();i++) {
            int bit = tolower(s[i]) - 'a';
            if((badChar >> bit) & 1) {
                string left = longestNiceSubstring(s.substr(0,i));
                string right = longestNiceSubstring(s.substr(i+1));
                return (left.length() >= right.length())? left:right;
            }
        }
        return s;

    }
};