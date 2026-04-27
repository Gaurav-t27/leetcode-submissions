class Solution {
public:
    int longestPalindrome(string s) {
        bitset<128> bs;

        int count = 0;
        for(char c:s) {
            if(bs.test(c)) {
                count += 2;
                bs.reset(c);
            } else {
                bs.set(c);
            }
        }

        return bs.any() ? count+1: count;
    }
};