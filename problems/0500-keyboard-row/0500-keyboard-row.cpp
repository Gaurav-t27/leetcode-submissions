class Solution {
public:

    vector<string> findWords(vector<string>& words) {
        int rowMap[26] = {-1};
        string rows[] = {"qwertyuiop","asdfghjkl","zxcvbnm"};
        for(int i=0;i<3;i++) {
            for(char c:rows[i]) rowMap[c-'a'] = i;
        }

        
        vector<string> res;
        for(const auto& w: words) {
            int firstCharRow = rowMap[tolower(w[0])-'a'];
            bool valid = true;
            for(int i=1;i<w.size();i++) {
                if(rowMap[tolower(w[i])-'a'] != firstCharRow) {
                    valid = false;
                    break;
                }
            }
            if(valid) res.push_back(w);
        }
        return res;
    }
};