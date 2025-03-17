class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove_if(s.begin(), s.end(),[](unsigned char c){return !isalnum(c);}) , s.end());
        transform(s.begin(),s.end(), s.begin(), [](unsigned char c){return tolower(c);});
        int l = 0, r = s.size() - 1;

        while(l <= r)
        {
            if(s[l] != s[r])
                return false;
            
            l++;
            r--;
        }
        return true;     
    }
};