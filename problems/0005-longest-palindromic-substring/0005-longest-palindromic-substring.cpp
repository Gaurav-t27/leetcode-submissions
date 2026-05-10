class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n<2) return s;
        int start = 0, max_len = 0;
        for(int i=0;i<n;i++) {
            int low = i, high = i+1;
            while(low>=0 && high<n && s[low] == s[high]) {
                int len = high-low+1;
                if(len > max_len) {
                    max_len = len;
                    start = low;
                }
                low--;
                high++;
            }

            low = i, high = i;
            while(low>=0 && high<n && s[low] == s[high]) {
                int len = high-low+1;
                if(len > max_len) {
                    max_len = len;
                    start = low;
                }
                low--;
                high++;
            }
        }
        return s.substr(start, max_len);
    }
};