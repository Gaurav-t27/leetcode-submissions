class Solution {
public:
    int hammingWeight(int n) {
        int sz = sizeof(int);
        int count = 0;
        for(int i=0;i<8*sz;i++) {
            if(n & (1<<i))
                count++;
        }
        return count;
    }
};