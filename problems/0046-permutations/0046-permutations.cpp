class Solution {
    public:
        vector<vector<int>> res;
        void backtrack(const vector<int>& nums, vector<int>& path, vector<bool>& used)
        {
            if(path.size() == nums.size())
                res.push_back(path);

            for(int i=0; i<nums.size();i++)
            {
                if(used[i]) continue;
                path.push_back(nums[i]);
                used[i] = true;
                backtrack(nums, path, used);
                path.pop_back();
                used[i] = false;
            }
        }
        vector<vector<int>> permute(vector<int>& nums) {
            vector<int> path;
            vector<bool> used(nums.size(), false);

            backtrack(nums, path, used);
            return res;
        }
    };