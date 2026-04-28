class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        
        vector<int> res(n,0);

        int start = (k>0)? 1:n+k;
        int end = (k>0)? k:n-1;

        int currSum = 0;
        for(int i=start;i<=end;i++) {
            currSum += code[i];
        }

        for(int i=0;i<n;i++) {
            res[i] = currSum;

            currSum -= code[start%n];

            start++;
            end++;

            currSum += code[end%n];
        }
        return res;
    }
};