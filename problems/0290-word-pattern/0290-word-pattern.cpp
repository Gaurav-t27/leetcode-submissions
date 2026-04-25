class Solution {
public:
    vector<string> split(string s) {
        vector<string> result;
        size_t start = 0;
        while(true) {
            size_t pos = s.find(" ", start);
            if(pos == std::string::npos) {
                result.push_back(s.substr(start));
                break;
            }
            result.push_back(s.substr(start, pos-start));
            start = pos + 1;
        }
        return result;
    }
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> p_to_s;
        unordered_map<string, char> s_to_p;

        vector<string> words = split(s);
        int n = words.size();
        int m = pattern.size();
        if(n!=m) return false;
        if(n==1) return true;
            
        for(int i=0;i<m;i++) {
            char p = pattern[i];
            string& w = words[i];

            auto [it_p, ins_p] = p_to_s.try_emplace(p,w);
            if(!ins_p && it_p->second != w) return false;

            auto [it_s, ins_s] = s_to_p.try_emplace(w,p);
            if(!ins_s && it_s->second != p) return false;
            /*if(p_to_s.find(p) != p_to_s.end()) {
                if(p_to_s[p] != w) {return false;}
            } else {
                p_to_s[p] = w;
            }

            if(s_to_p.find(w) != s_to_p.end()) {
                if(s_to_p[w] != p) {return false;}
            } else {
                s_to_p[w] = p;
            }*/
        }

        return true;
    }
};