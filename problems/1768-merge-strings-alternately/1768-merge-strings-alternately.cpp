class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();

        int i=0;
        string res;
        res.reserve(m+n);
        while(i<m && i<n) {
            res += word1[i];
            res += word2[i];
            i++;
        }
        while(i<m) {
            res += word1[i];
            i++;
        }
        while(i<n) {
            res += word2[i];
            i++;
        }
        return res;
    }
};