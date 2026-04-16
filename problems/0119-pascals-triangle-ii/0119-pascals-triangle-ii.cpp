class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex;
        vector<int> res(n+1,1);
        long long current = 1;
        for(int i=1;i<=n/2;i++) {
            current = current * (n-i+1)/i;
            res[i] = (int) current;
        }
        int left = 0;
        int right = n;
        while(left < right) {
            res[right] = res[left];
            left++;
            right--;
        }
        return res;
    }
};