class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int lastIndex = -1;
        int maxPos = 0;
        int jumps = 0;

        while(maxPos < n-1 && lastIndex != maxPos) {

            int i = maxPos;
            int temp = maxPos;
            while(i > lastIndex) {
                maxPos = max(maxPos, i+nums[i]);
                i--;
            }

            jumps++;
            lastIndex = temp;
        }

        return maxPos >= n-1 ? jumps : -1;
    }
};
