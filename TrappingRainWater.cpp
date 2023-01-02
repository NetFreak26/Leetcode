class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> leftMax(n, 0);

        for(int i=1; i<n; i++) {
            leftMax[i] = max(leftMax[i-1], height[i-1]);
        }

        int rightMax = 0;
        int waterTrapped = 0;
        for(int i=n-1; i>=0; i--) {
            waterTrapped += min(leftMax[i], rightMax) > height[i] ? min(leftMax[i], rightMax) - height[i] : 0;
            rightMax = max(rightMax, height[i]);
        }

        return waterTrapped;
    }
};
