class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> stops(1001,0);

        for(auto& trip: trips) {
            stops[trip[1]] += trip[0];
            stops[trip[2]] -= trip[0];
        }

        int curr = 0;
        for(int i=0;i<=1000;i++) {
            curr += stops[i];
            if(curr>capacity) return false;
        }
        return true;
    }
};