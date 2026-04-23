class Solution {
public:
    int tribonacci(int n) {
        int ti0 = 0;
        int ti1 = 1;
        int ti2 = 1;
        int ti3 = 0;
        if(n==0) return ti0;
        if(n==1) return ti1;
        if(n==2) return ti2;
        for(int i=3;i<=n;i++) {
            ti3 = ti0 + ti1 + ti2;
            ti0 = ti1;
            ti1 = ti2;
            ti2 = ti3;
        }
        return ti3;
    }
};