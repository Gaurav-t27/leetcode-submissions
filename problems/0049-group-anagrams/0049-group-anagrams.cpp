class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um;

        for(const string& str: strs)
        {
            string key(26, '0');
            for(char c:str)
            {
                key[c-'a']++;
            }
            um[key].push_back(str);
        }

        vector<vector<string>> res;
        for(auto e:um)
        {
            res.push_back(e.second);
        }
        return res;
    }
};