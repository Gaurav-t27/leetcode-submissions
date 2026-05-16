class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int low=0, high=n-1;
        while(low<high) {
            while(low<high && !std::isalnum(s[low]))
                low++;
            while(low<high && !std::isalnum(s[high]))
                high--;
            if(std::tolower(s[low]) != std::tolower(s[high]))
                return false;
            low++;
            high--;
        }
        return true;
    }
};