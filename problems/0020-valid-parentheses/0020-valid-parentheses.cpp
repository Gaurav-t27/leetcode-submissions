class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> hm{
            {'(',')'},
            {'[',']'},
            {'{','}'}
        };

        stack<char> st;
        for (auto c : s)
        {
            
            if (hm.find(c) != hm.end())
            {
                st.push(c);
            }
            else
            {
                if(st.empty())
                    return false;
                char d = st.top();
                st.pop();
                if (hm[d] != c)
                {
                    return false;
                }
            }
        }

        if (st.empty())
            return true;

        return false;

    }
};