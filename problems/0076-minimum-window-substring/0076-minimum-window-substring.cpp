class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length())
            return "";
        unordered_map<char, int> hmt;
        unordered_map<char, int> hms;

        for (int i = 0;i < t.length();i++)
        {
            hmt[t[i]]++;
        }
        int have = 0, need = hmt.size();

        pair<int, int> lenRange;
        lenRange.first = -1, lenRange.second = -1;
        int len = 0, l = 0, r = 0, minLen = INT_MAX;
        while (r < s.length())
        {
            hms[s[r]]++;
            if (hmt.find(s[r]) != hmt.end() && hmt[s[r]] == hms[s[r]])
            {
                have++;
            }
            while (have == need && l <= r)
            {
                len = r - l + 1;
                if (len < minLen)
                {
                    lenRange.first = l, lenRange.second = r;
                    minLen = len;
                }

                hms[s[l]]--;
                if (hmt.find(s[l]) != hmt.end() && hms[s[l]] < hmt[s[l]])
                {
                    have--;
                }
                l++;
            }
            r++;
        }

        if (lenRange.first == -1)
            return "";
        return s.substr(lenRange.first, minLen);
    }
};