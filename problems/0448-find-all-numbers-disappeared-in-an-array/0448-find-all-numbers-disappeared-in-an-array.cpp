class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> us(nums.begin(),nums.end());

        vector<int> res;
        for(int i=1;i<=n;i++) {
            if(us.find(i) == us.end()) {
                res.push_back(i);
            }
        }
        return res;
    }
};