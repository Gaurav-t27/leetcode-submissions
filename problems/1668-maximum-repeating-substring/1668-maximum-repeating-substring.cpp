class Solution {
public:

    int maxRepeating(string sequence, string word) {
        int m = sequence.size();
        int n = word.size();
        int max_count = 0;

        for(int i=0;i<m;) {
            int j=0,k=i, count = 0;
            while(k<m && sequence[k]==word[j]) {
                k++;
                j++;
                if(j == n) {
                    count++;
                    j = 0;
                    if(count> max_count) max_count = count;
                }
            }
            i++;
        }
        return max_count;
    }
};