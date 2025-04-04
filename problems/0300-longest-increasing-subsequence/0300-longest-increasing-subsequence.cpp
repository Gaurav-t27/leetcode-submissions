class Solution {
public:
    vector<int> dp;
    int dpUtil(const vector<int>& numG, int i)
    {
        if (dp[i] != -1)
            return dp[i];

        int maxLen = 1;
        for (int j=i+1;j<numG.size();j++)
        {
            if(numG[i]<numG[j])
                maxLen = max(maxLen, 1 + dpUtil(numG, j));
        }

        dp[i] = maxLen;
        return maxLen;
    }
    int lengthOfLIS(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        int maxPath = 1;

        for (int i=0;i<nums.size();i++)
        {
            maxPath = max(maxPath, dpUtil(nums, i));
        }

        return maxPath;
    }
};