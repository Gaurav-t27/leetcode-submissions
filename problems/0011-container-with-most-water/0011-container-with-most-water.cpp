class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0,r=heights.size()-1;
        int maxVol = 0;
        while(l<r)
        {
            int vol=(r-l)*min(heights[l],heights[r]);
            maxVol=max(vol,maxVol);
            if(heights[l] <= heights[r])
                l++;
            else
                r--;

        }
        return maxVol;
    }
};