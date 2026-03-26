class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int max = 0;
        vector<int> vec(256,-1);
        for(int end=0;end<s.size();end++) {
            char current = s[end];
            if(vec[current] >= start) {
                start = vec[current] + 1;
            }
            vec[current] = end;
            
            if(end-start+1 > max) {
                max = end - start + 1;
            }
        }
        return max;
    }
};