class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hs;

        for(auto e: nums)
        {
            hs.insert(e);
        }
        int maxSeq = 0;
        for(auto e: hs)
        {
            if(hs.find(e-1) == hs.end())
            {
                int seq = 1;
                while(hs.find(e+1)!=hs.end())
                {
                    e++;
                    seq++;
                }
                maxSeq = max(seq, maxSeq);
            }
        }
        return maxSeq;
    }
};