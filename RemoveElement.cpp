class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0;
        int r = nums.size() - 1;

        int remLength = 0;
        while(l <= r) {
            if(nums[l] == val) {
                swap(nums[l], nums[r--]);
            } else {
                l++;
                remLength++;
            }
        }

        return remLength;
    }
};
