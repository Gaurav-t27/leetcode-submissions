class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0, l = 0;
        std::unordered_set<char> hs;
        for (int r = 0;r < s.size();r++)
        {
            while (hs.find(s[r]) != hs.end())
            {
                hs.erase(s[l]);
                l++;
            }
            hs.insert(s[r]);
            maxLen = std::max(maxLen, r - l +1);
        }
        return maxLen;
    }
};