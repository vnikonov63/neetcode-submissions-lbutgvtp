class Solution {
public:
    int maxArea(vector<int>& heights) {
        int p1 = 0, p2 = heights.size() - 1;
        int curr_area = 0;
        int result = INT_MIN;
        while (p1 < p2) {
            curr_area = (p2 - p1) * min(heights[p1], heights[p2]);
            result = max(result, curr_area);
            if (heights[p1] < heights[p2]) 
                p1++;
            else 
                p2--;
        }

        return result;
    }
};
