class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(m!=n) return false;

        vector<int> res(26,0);
        for(int i=0;i<n;i++) {
            res[s[i]-'a']++;
            res[t[i]-'a']--;
        }
        for(int i:res) {
            if(i!=0) return false;
        }
        return true;
    }
};