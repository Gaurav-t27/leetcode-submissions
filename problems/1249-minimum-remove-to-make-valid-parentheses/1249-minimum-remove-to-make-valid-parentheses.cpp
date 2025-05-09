class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        vector<int> indexTobeRemoved(s.size(),false);
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else if(s[i] == ')')
            {
                if(!st.empty())
                {
                    st.pop();
                }
                else
                {
                    indexTobeRemoved[i] = true;
                }
            }
        }
        
        while(!st.empty())
        {
            indexTobeRemoved[st.top()] = true;
            st.pop();
        }
        
        string res = "";
        for(int i=0;i<s.size();i++)
        {
            if(!indexTobeRemoved[i])
                res += s[i];
        }
        
        return res;
    }
};