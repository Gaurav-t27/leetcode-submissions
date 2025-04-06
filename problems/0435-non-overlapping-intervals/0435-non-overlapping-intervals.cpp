class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0 || intervals.size() == 1)
            return 0;
        sort(intervals.begin(), intervals.end());
        int lastEnd = intervals[0][1];
        int count = 0;

        for (int i=1;i<intervals.size();i++)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if (start >= lastEnd)
                lastEnd = intervals[i][1];
            else
            {
                lastEnd = min(end, lastEnd);
                count++;
            }

        }
        return count;
    }
};