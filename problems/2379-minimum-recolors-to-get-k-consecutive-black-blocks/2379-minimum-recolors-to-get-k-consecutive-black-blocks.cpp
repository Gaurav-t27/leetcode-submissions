class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();

        int min_count = INT_MAX, count = 0;
        for(int i=0;i<k;i++) {
            if(blocks[i] == 'W') count++;
        }
        min_count = count;

        for(int high=k;high<n;high++) {
            if(blocks[high] == 'W') count++;

            if(blocks[high - k] == 'W') count--;
            min_count = min(count, min_count);
        }
        return min_count;
    }
};