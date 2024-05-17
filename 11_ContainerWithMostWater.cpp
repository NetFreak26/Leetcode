class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int max_water = 0;
        while (l < r) {
            if (height[l] < height[r]) {
                max_water = max(max_water, height[l] * (r - l));
                l++;
            } else {
                max_water = max(max_water, height[r] * (r - l));
                r--;
            }
        }
        return max_water;
    }
};
