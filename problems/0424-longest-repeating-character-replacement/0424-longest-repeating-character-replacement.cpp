class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        int len = 0, maxLen = 0, maxFreq = 0;
        vector<int> v(26,0);

        while (r < s.size())
        { 
            v[s[r]-'A']++;
            maxFreq=max(maxFreq, v[s[r]-'A']);
            len = r - l + 1;
            if (len - maxFreq > k)
            {
                v[s[l]-'A']--;
                l++;
            }
            
            len = r - l + 1;
            maxLen = max(len, maxLen);
            r++;
        }
        return maxLen;
    }
};