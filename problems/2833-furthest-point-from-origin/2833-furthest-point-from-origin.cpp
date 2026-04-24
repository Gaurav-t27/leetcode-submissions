class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int nLR = 0;
        int n_ = 0;

        for(char c:moves) {
            if(c == 'L') nLR--;
            else if(c == 'R') nLR++;
            else n_++;
        }
        return std::abs(nLR) + n_;
    }
};