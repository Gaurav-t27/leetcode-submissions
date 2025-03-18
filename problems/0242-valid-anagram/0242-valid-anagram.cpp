class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;

        unordered_map<char, int> hs, ht;
        for(int i=0;i<s.size();++i)
        {
            hs[s[i]]++;
            ht[t[i]]++;
        }
        if(hs.size()!=ht.size())
            return false;
        
        if(hs != ht)
            return false;
            
        return true;
    }
};