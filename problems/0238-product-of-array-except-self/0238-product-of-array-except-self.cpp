class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;

        int pre = 1, suf = 1;
        for(int i=0;i<nums.size();i++)
        {
            res.push_back(pre);
            pre = pre * nums[i];
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            res[i] = res[i]*suf;
            suf = suf * nums[i];
        }

        return res;
    }
};