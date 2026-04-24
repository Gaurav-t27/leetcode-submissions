class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = groups.size();
        if(n==1) return words;
        vector<string> res;
        int last = groups[0];
        res.push_back(std::move(words[0]));
        for(int i=1;i<n;i++) {
            if(last != groups[i]) {
                res.push_back(std::move(words[i]));
                last = groups[i];
            }
        }
        
        return res;
    }
};