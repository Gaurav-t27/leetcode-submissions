class Solution {
public:
    int largestInteger(int num) {
        std::priority_queue<int> evens;
        std::priority_queue<int> odds;

        std::string s = std::to_string(num);
        for(char c:s) {
            int d = c - '0';
            if(d%2 == 0) evens.push(d);
            else odds.push(d);
        }
        std::string res = "";
        for(char c:s) {
            int d = c - '0';
            if(d%2 == 0) { res += std::to_string(evens.top()); evens.pop(); }
            else { res += std::to_string(odds.top()); odds.pop(); }
        }
        return std::stoi(res);
    }
};